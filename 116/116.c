/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL) return ;
    struct TreeLinkNode *pCur = root;
    for(;;){
        struct TreeLinkNode *pHead = pCur->left;
        while(pCur != NULL){
            //满二叉树,左右孩子同时为空或非空
            if(pCur->left != NULL){
                pCur->left->next = pCur->right;
                pCur->right->next = pCur->next == NULL ? NULL : pCur->next->left;
            }
            pCur = pCur->next;
        }
        pCur = pHead;
        if(pHead == NULL) break;
    }
}