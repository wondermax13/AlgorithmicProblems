/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        
        if(head == null) return null;
        
        HashMap<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();
        
        RandomListNode index = head;
        while(index != null) {
            
            map.put(index, new RandomListNode(index.label));
            index = index.next;
        }
        
        index = head;
        while(index != null) {
            
            map.get(index).next = map.get(index.next);
            map.get(index).random = map.get(index.random);
            
            index = index.next;
        }
        
        return map.get(head);
    }
}