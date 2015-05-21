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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vResult;
        if(root == NULL) return vResult;
        queue<TreeNode *> q;
        q.push(root);
        bool bReverse = false;
        while(!q.empty()){
            int nQueueSize = q.size();
            vector<int> vEachLevel;
            for(int i = 0; i < nQueueSize; i++){
                TreeNode *pCur = q.front();
                q.pop();
                vEachLevel.push_back(pCur->val);
                if(pCur->left != NULL){
                    q.push(pCur->left);
                }
                if(pCur->right != NULL){
                    q.push(pCur->right);
                }
            }
            if(bReverse == true){
                reverse(vEachLevel.begin(),vEachLevel.end());
            }
            bReverse = !bReverse;
            vResult.push_back(vEachLevel);
        }

        return vResult;
    }
};