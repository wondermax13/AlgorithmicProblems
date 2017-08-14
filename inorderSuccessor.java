/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        
        return search(root, p);
        
    }
    
    protected TreeNode search(TreeNode node, TreeNode p) {
        
        if(node == null) return null;
        
        if(node.val <= p.val) {
            
            TreeNode result = search(node.right, p);
            return result;
        }
        
        else {
            
            TreeNode result = search(node.left, p);
            if(result == null) {
                
                return node;
            }
            
            return result;
        }
    }
}