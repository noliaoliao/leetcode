/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 
struct TreeNode *bst(struct TreeNode *treehead, struct ListNode *listhead){
    struct ListNode *pPre = NULL;
    struct ListNode *pFast = listhead;
    struct ListNode *pSlow = listhead;
    struct ListNode *pLeft = NULL;
    struct ListNode *pRight = NULL;
    //链表为空
    if(listhead == NULL ){
        treehead = NULL;
        return treehead;
    }
    //链表只有一个节点
    if(listhead->next == NULL){
        treehead->val = listhead->val;
        treehead->left = NULL;
        treehead->right = NULL;
        return treehead;
    }
    //找到链表的中点
    while(pSlow != NULL && pFast != NULL && pFast->next != NULL){
        pPre = pSlow;
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
    //处理下链表长度为2的情况
    if(pSlow->next == NULL){
        treehead->val = pSlow->val;
        treehead->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        treehead->left->val = listhead->val;
        treehead->left->left = NULL;
        treehead->left->right = NULL;
        treehead->right = NULL;
        return treehead;
    }
    //一般情况
    pLeft = listhead;
    pRight = pSlow->next;
    //pSlow->next = NULL;
    treehead->val = pSlow->val;
    pPre->next = NULL;
    treehead->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treehead->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treehead->left = bst(treehead->left,pLeft);
    treehead->right = bst(treehead->right,pRight);
    
    return treehead;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    struct TreeNode *treenode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    return bst(treenode,head);
}