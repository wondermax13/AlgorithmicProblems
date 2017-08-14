/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        
        StringBuffer buff = new StringBuffer();
        
        inOrderTraverse(root, buff);
        return buff.toString();
    }
    
    protected void inOrderTraverse(TreeNode node, StringBuffer buff) {
        
        String target = node == null ? "null" : String.valueOf(node.val);
        buff.append(target).append(",");
        
        if(node != null) {
            
            inOrderTraverse(node.left, buff);
            inOrderTraverse(node.right, buff);
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        Deque<String> list = new LinkedList<String>();
        
        list.addAll(Arrays.asList(data.split(",")));
        
        if(list.size() == 1) return null;
        
        TreeNode root = createTree(list);
        
        return root;
    }
    
    protected TreeNode createTree(Deque<String> list) {
        
        TreeNode node;
        String front = list.remove();
        
        if(front == "null") {
            node = null;
        }
        else {
            node = new TreeNode(Integer.valueOf(front));
            node.left = createTree(list);
            node.right = createTree(list);
        }
        
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));