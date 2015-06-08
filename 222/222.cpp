/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root == NULL) return 0;
    int nLeft = 0;
    for(struct TreeNode* p = root->left; p != NULL; p = p->left) nLeft++;
    int nRight = 0;
    for(struct TreeNode* p = root->right; p != NULL; p = p->right) nRight++;
    
    //满二叉树
    if(nLeft == nRight) return (1<<(nRight+1))-1;
    if(nRight == 0) return 2;
    return countNodes(root->left)+countNodes(root->right)+1;
}