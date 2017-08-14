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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if(!covers(root, p) || !covers(root, q)) {
            
            return null;
        }

        return search(root, p, q);
    }
    
    protected TreeNode search(TreeNode node, TreeNode p, TreeNode q) {
        
        
        if(node == null || node == p || node == q) {
            
            return node;
        }
        
        boolean isPOnLeft = covers(node.left, p);
        boolean isQOnLeft = covers(node.left, q);
        
        if(isPOnLeft != isQOnLeft) {
            
            return node;
        }
        
        TreeNode child = isPOnLeft ? node.left : node.right;
        
        return search(child, p, q);
    }
    
    protected boolean covers(TreeNode node, TreeNode p) {
        
        if(node == null) return false;
        
        if(node == p) return true;
        
        return (covers(node.left, p) || covers(node.right, p));
    }
}