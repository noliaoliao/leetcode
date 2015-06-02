/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root != NULL){
            m_stack.push(root);
            m_currNode = root->left;
        }else{
            m_currNode = NULL;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (m_stack.empty() == false || m_currNode != NULL);
    }

    /** @return the next smallest number */
    int next() {
        int ret = 0;
        //中序遍历,一次取一个最小的值
        if(m_currNode != NULL || m_stack.empty() != true){
            //向左走到底
            while(m_currNode != NULL){
                m_stack.push(m_currNode);
                m_currNode = m_currNode->left;
            }
            m_currNode = m_stack.top();
            m_stack.pop();
            ret = m_currNode->val;
            m_currNode = m_currNode->right;
        }
        return ret;
    }

private:
    stack<struct TreeNode*> m_stack;   
    TreeNode *m_currNode;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */