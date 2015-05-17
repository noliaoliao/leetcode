/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *createBST(struct TreeNode *root, int *nums, int start, int end){
    if(nums == NULL || start > end) return NULL;
    //处理长度为1的情况
    if(start == end){
        root->val = nums[start];
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    //递归进行
    int mid = (start+end)/2;
    root->val = nums[mid];
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = createBST(root->left,nums,start,mid-1);
    root->right = createBST(root->right,nums,mid+1,end);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0) return NULL;
    struct TreeNode *head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    return createBST(head,nums,0,numsSize-1);
}