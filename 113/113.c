//递归遍历即可

class Solution {
public:
    void getAllPath(TreeNode *root, int sum, vector<vector<int>> &vAllPath, vector<int> vEachPath){
        if(root == NULL) return;
        vEachPath.push_back(root->val);
        if(root->val == sum && root->left == NULL && root->right == NULL){
            vAllPath.push_back(vEachPath);
        }else{
            getAllPath(root->left,sum-root->val,vAllPath,vEachPath);
            getAllPath(root->right,sum-root->val,vAllPath,vEachPath);
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vRet;
        vector<int> vEach;
        getAllPath(root,sum,vRet,vEach);
        return vRet;
    }
};