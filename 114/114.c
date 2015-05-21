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
        //��ƽ������
        struct TreeNode* pRight = flattenTree(root->left);
        //��������ƽ�������������һ���ڵ�,������������
        struct TreeNode* pWalkRight = pRight;
        while(pWalkRight->right != NULL){
            pWalkRight = pWalkRight->right;
        }
        //��ƽ������
        pWalkRight->right = flattenTree(root->right);   
        root->right = pRight;
        root->left = NULL;
    }else{
        //������Ϊ��,ֱ�ӵݹ鴦������������
        root->right = flattenTree(root->right);
    }
    
    return root;
}

void flatten(struct TreeNode* root) {
    flattenTree(root);
}