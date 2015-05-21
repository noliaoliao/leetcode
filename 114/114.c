/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* flattenTree(struct TreeNode* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return root;

    if(root->left != NULL){
        //变平左子树
        struct TreeNode* pRight = flattenTree(root->left);
        //遍历到变平的左子树的最后一个节点,和右子树连接
        struct TreeNode* pWalkRight = pRight;
        while(pWalkRight->right != NULL){
            pWalkRight = pWalkRight->right;
        }
        //变平右子树
        pWalkRight->right = flattenTree(root->right);   
        root->right = pRight;
        root->left = NULL;
    }else{
        //左子树为空,直接递归处理右子树即可
        root->right = flattenTree(root->right);
    }
    
    return root;
}

void flatten(struct TreeNode* root) {
    flattenTree(root);
}