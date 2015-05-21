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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vRightSideView;
        if(root == NULL) return vRightSideView;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int nQueueSize = q.size();
            //每层的最后一个节点压入vector
            vRightSideView.push_back(q.back()->val);
            for(int i = 0; i < nQueueSize; i++){
                TreeNode *pCur = q.front();
                q.pop();
                if(pCur->left != NULL){
                    q.push(pCur->left);
                }
                if(pCur->right != NULL){
                    q.push(pCur->right);
                }
            }
        }

        return vRightSideView;
    }
};