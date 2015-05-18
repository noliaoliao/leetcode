/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *buildTreeByPreAndInorder(int* preOrderStart, int* preOrderEnd, int* inorderStart, int* inorderEnd){
    //树的根节点是preOrder的第一个数
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preOrderStart[0];
    root->left = NULL;
    root->right = NULL;
    if(preOrderStart == preOrderEnd) return root;

    //在中序遍历序列中找到根节点
    int* pRootInorder = inorderStart;
    while(pRootInorder < inorderEnd && *pRootInorder != preOrderStart[0]) pRootInorder++;
    int nLeftLen = pRootInorder - inorderStart;
    //构建左子树
    if(nLeftLen > 0){
        root->left = buildTreeByPreAndInorder(preOrderStart+1,preOrderStart+nLeftLen,inorderStart,pRootInorder-1);
    }
    //构建右子树
    if(nLeftLen < inorderEnd-inorderStart){
        root->right = buildTreeByPreAndInorder(preOrderStart+nLeftLen+1,preOrderEnd,pRootInorder+1,inorderEnd);
    }

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorder == NULL || inorder == NULL || preorderSize <= 0 || inorderSize <= 0) return NULL;
    return buildTreeByPreAndInorder(preorder,preorder+preorderSize-1,inorder,inorder+inorderSize-1);
}