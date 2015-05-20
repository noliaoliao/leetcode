/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumTreeNum(struct TreeNode* root, int nPre){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return nPre*10+root->val;
    //左右子树之和
    return sumTreeNum(root->left,nPre*10+root->val) + sumTreeNum(root->right,nPre*10+root->val);
}

int sumNumbers(struct TreeNode* root) {
    if(root == NULL) return 0;
    return sumTreeNum(root,0);
}