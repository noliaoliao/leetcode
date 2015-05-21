/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return ;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()){
            int nQueueSize = q.size();
            for(int i = 0; i < nQueueSize; i++){
                TreeLinkNode *pCur = q.front();
                q.pop();
                //队列最后一个元素特殊处理
                if(i == nQueueSize - 1){
                    pCur->next = NULL;
                }else{
                    pCur->next = q.front();
                }
                if(pCur->left != NULL){
                    q.push(pCur->left);
                }
                if(pCur->right != NULL){
                    q.push(pCur->right);
                }
            }
        }
    }
};