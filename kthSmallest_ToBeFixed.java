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
    public int kthSmallest(TreeNode root, int k) {
        
        return findkthSmallest(root, k).val;
    }
    
    protected NodeIndex findkthSmallest(TreeNode node, int k) {
        
        int index;
        NodeIndex nodeIndex = new NodeIndex(),
                  leftIndex = null,
                  rightIndex = null;
        
        if(node == null) {
            
            nodeIndex.noOfNodes = 0;
            nodeIndex.val = -1;
            
            return nodeIndex;
        }
        else {
            
            leftIndex = findkthSmallest(node.left, k);

            if(leftIndex.val == -1) {
                
                if(k-1 == leftIndex.noOfNodes) {
                    
                    nodeIndex.val = node.val;
                    
                    return nodeIndex;
                }
                
                rightIndex = findkthSmallest(node.left, k-leftIndex.noOfNodes-1);

                if(rightIndex.val == -1) {
                    
                    nodeIndex.noOfNodes = leftIndex.noOfNodes + rightIndex.noOfNodes + 1;
                    nodeIndex.val = (k==0 || k==1) ? node.val : -1;
                }
                else {
                    
                    nodeIndex.noOfNodes = leftIndex.noOfNodes + rightIndex.noOfNodes + 1;
                    nodeIndex.val = rightIndex.val;
                }
            }
            else {
                
                nodeIndex.noOfNodes = 0;
                nodeIndex.val = leftIndex.val;
            }
        }
        
        return nodeIndex;
    }
    
    protected class NodeIndex {
        
        int val;
        int noOfNodes;
    }
}