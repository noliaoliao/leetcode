/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
#define MAX_TWO(A,B) ((A)>(B) ? (A) : (B))
#define MAX_THREE(A,B,C) MAX_TWO(MAX_TWO(A,B),C)
#define MAX_FOUR(A,B,C,D) MAX_TWO(MAX_THREE(A,B,C),D)

#define MAX_TWO(A,B) ((A)>(B) ? (A) : (B))
#define MAX_THREE(A,B,C) MAX_TWO(MAX_TWO(A,B),C)
#define MAX_FOUR(A,B,C,D) MAX_TWO(MAX_THREE(A,B,C),D)

/**
    路径最大值有4种情况
    1.root
    2.root+左子树某路径
    3.root+右子树某路径
    4.root+左子树某路径+右子树某路径
*/
int eachPathSum(struct TreeNode* root, int* nMaxPathSum){
    int nLeftPathSum = 0;
    int nRightPathSum = 0;
    int nPathSum = 0;
    if(root->left == NULL && root->right == NULL){
        nPathSum = root->val;
        *nMaxPathSum = MAX_TWO(*nMaxPathSum,nPathSum);
        return nPathSum;
    }
    if(root->left != NULL && root->right == NULL){
        nLeftPathSum = eachPathSum(root->left,nMaxPathSum);
        nPathSum = MAX_TWO(nLeftPathSum+root->val,root->val);
        *nMaxPathSum = MAX_FOUR(*nMaxPathSum,nLeftPathSum,root->val,nPathSum);
        return nPathSum;
    }
    if(root->left == NULL && root->right != NULL){
        nRightPathSum = eachPathSum(root->right,nMaxPathSum);
        nPathSum = MAX_TWO(nRightPathSum+root->val,root->val);
        *nMaxPathSum = MAX_FOUR(*nMaxPathSum,nRightPathSum,root->val,nPathSum);
        return nPathSum;
    }
    //对外连接的最大值
    nLeftPathSum = eachPathSum(root->left,nMaxPathSum);
    nRightPathSum = eachPathSum(root->right,nMaxPathSum);
    nPathSum = MAX_THREE(root->val+nLeftPathSum,root->val+nRightPathSum,root->val);
    *nMaxPathSum = MAX_THREE(*nMaxPathSum,nPathSum,MAX_FOUR(root->val,nLeftPathSum,nRightPathSum,root->val+nLeftPathSum+nRightPathSum));

    return nPathSum;    
}

int maxPathSum(struct TreeNode* root) {
    if(root == NULL) return 0;
    int nMaxPathSum = root->val;
    eachPathSum(root,&nMaxPathSum);
    return nMaxPathSum;
}