/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        
        if(head == null || head.next == null) return head;
        
        ListNode curr = head, next = head.next, newHead = head.next, prev = null;
        
        
        while(curr != null && curr.next != null) {
            
            next = curr.next;
            
            if(prev != null) {
                
                prev.next = next;
            }
            
            curr.next = next.next;
            next.next = curr;
            
            prev = curr;
            curr = curr.next;
        }
        
        return newHead;
    }
}