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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        
        List<List<Integer>> lists;// = new ArrayList<List<Integer>>();
        
        if(root == null) {
            
            lists = new ArrayList<List<Integer>>();
        }
        else {
            
            int leftNodes = getLeftNodes(root, 0),
                rightNodes = getRightNodes(root, 0);
                
            int totalLevels = 1 + leftNodes + rightNodes;
            
            lists = new ArrayList<List<Integer>>(totalLevels);
            for(int level = 1; level < totalLevels + 1; level++) {
                
                lists.add(new ArrayList<Integer>());
            }
            
            verticalTraversalBFS(root, lists, leftNodes);
        }
        
        return lists;
    }
    
    protected int getLeftNodes(TreeNode node, int noOfNodes) {
        
        if(node == null) {
            return noOfNodes;
        }
        
        int leftNodes = node.left == null ? noOfNodes : getLeftNodes(node.left, noOfNodes + 1);
        int rightNodes = node.right == null ? noOfNodes : getLeftNodes(node.right, noOfNodes - 1);
        
        return Math.max(leftNodes, rightNodes);
    }
    
    protected int getRightNodes(TreeNode node, int noOfNodes) {
        
        int rightNodes = node.right == null ? noOfNodes : getRightNodes(node.right, noOfNodes + 1);
        int leftNodes = node.left == null ? noOfNodes : getRightNodes(node.left, noOfNodes - 1);
        
        return Math.max(leftNodes, rightNodes);
    }
    
    protected void verticalTraversalBFS(TreeNode root, List<List<Integer>> lists, int leftNodes) {
        
        Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
        
        Queue<TreeNode> valQ = new LinkedList<TreeNode>();
        Queue<Integer> colQ = new LinkedList<Integer>();
        
        valQ.add(root);
        colQ.add(leftNodes);
        
        while(!valQ.isEmpty()) {
            
            TreeNode node = valQ.poll();
            int col       = colQ.poll();
            
            lists.get(col).add(node.val);
            
            if(node.left != null) {
                
                valQ.add(node.left);
                colQ.add(col - 1);
            }
            if(node.right != null) {
                
                valQ.add(node.right);
                colQ.add(col + 1);
            }
        }
    }
    
/*
    RECURSIVE - DFS SOLUTION.
    SINCE THE VERTICAL ORDER IS IMP. THIS IS A BFS PROBLEM
protected void verticalTraversal(
        TreeNode node, List<List<Integer>> lists, int level) {
            
            if(node == null) {
                
                return;
            }
            
            verticalTraversal(node.left, lists, level - 1);
            
            lists.get(level).add(node.val);
            
            verticalTraversal(node.right, lists, level + 1);
    }*/
}