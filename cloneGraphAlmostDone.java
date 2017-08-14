/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        
        if(node == null) return null;
        
        HashMap<Integer, UndirectedGraphNode> map = new HashMap<Integer, UndirectedGraphNode>();
        HashSet<Integer> set = new HashSet<Integer>();
        
        UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
        map.put(node.label, newNode);
        
        Deque<UndirectedGraphNode> q = new LinkedList<UndirectedGraphNode>();
        
        q.add(node);
        
        while(!q.isEmpty()) {
            
            UndirectedGraphNode curr = q.pop();
            
            for(UndirectedGraphNode neighbour : curr.neighbors) {
                
                if(!map.containsKey(curr.label)) {
                    
                    map.put(neighbour.label, new UndirectedGraphNode(neighbour.label));
                    q.add(neighbour);
                }
                
                map.get(curr.label).neighbors.add(map.get(neighbour));
            }
        }
        
        return newNode;
    }
}