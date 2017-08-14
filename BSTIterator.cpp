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
        
        TreeNode* curr = root;
        
        while(curr != nullptr) {
            
            s.push(curr);
            curr = curr->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        TreeNode* front = s.top();
        s.pop();
        
        if(front->right != nullptr) {
            
            TreeNode* curr = front->right;
        
            while(curr != nullptr) {
            
                s.push(curr);
                curr = curr->left;
            }
        }
        
        return front->val;
        
    }
    
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */