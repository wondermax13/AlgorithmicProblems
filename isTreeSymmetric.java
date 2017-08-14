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
    bool isSymmetric(TreeNode* root) {
        
        
        if(root == NULL) {
            
            return true;
        }
        
        return areNodesMirrorImages(root, root);
    }
    
    bool areNodesMirrorImages(TreeNode* left, TreeNode* right) {
        
        bool result;
        
        bool leftNull = left == NULL,
             rightNull = right == NULL;
             
        if(leftNull && rightNull) return true;
             
        if(leftNull != rightNull) {
                
            result = false;
        }
        
        else {
            
            result = (left->val == right->val)
                && areNodesMirrorImages(left->left, right->right)
                && areNodesMirrorImages(left->right, right->left);

        }

        return result;
    }

    /*
        ITERATIVE APPROACH

        q.add(root);
        q.add(root);

        bool isSym = true;

        while(!q.isEmpty() && isSym) {

            t1 = q.poll();
            t2 = q.poll();

            isSym = process(t1, t2);

            if(isSym) {

                q.add(t1.left);
                q.add(t2.right);
                q.add(t1.right);
                q.add(t2.left);
            }
        }

        return isSym;
    */
};
