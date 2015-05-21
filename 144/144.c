/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preOrderTree(struct TreeNode *root,vector<int> &vResult){
        stack<struct TreeNode*> s;
        s.push(root);
        while(s.empty() != true){
            TreeNode* cur = s.top();
            s.pop();
            vResult.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vResult;
        if(root != NULL){
            preOrderTree(root,vResult);
        }
        return vResult;
    };
};