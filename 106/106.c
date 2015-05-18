/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 struct TreeNode *buildTreeByPostAndInorder(int* postOrderStart, int* postOrderEnd, int* inorderStart, int* inorderEnd){
    //树的根节点是postOrder的最后一个数
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postOrderEnd[0];
    root->left = NULL;
    root->right = NULL;
    if(postOrderStart == postOrderEnd) return root;

    //在中序遍历序列中找到根节点
    int* pRootInorder = inorderStart;
    while(pRootInorder < inorderEnd && *pRootInorder != postOrderEnd[0]) pRootInorder++;
    int nLeftLen = pRootInorder - inorderStart;
    //构建左子树
    if(nLeftLen > 0){
        root->left = buildTreeByPostAndInorder(postOrderStart,postOrderStart+nLeftLen-1,inorderStart,pRootInorder-1);
    }
    //构建右子树
    if(nLeftLen < inorderEnd-inorderStart){
        root->right = buildTreeByPostAndInorder(postOrderStart+nLeftLen,postOrderEnd-1,pRootInorder+1,inorderEnd);
    }

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(postorder == NULL || inorder == NULL || postorderSize <= 0 || inorderSize <= 0) return NULL;
    return buildTreeByPostAndInorder(postorder,postorder+postorderSize-1,inorder,inorder+inorderSize-1); 
}