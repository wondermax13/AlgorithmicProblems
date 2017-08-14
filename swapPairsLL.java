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
        
        if(head == null) {
            
            return null;
        }
        
        if(head.next == null) {
            
            return head;
        }
        
        ListNode curr = head;
        ListNode newHead = head.next;
        
        while(curr != null && curr.next != null) {
            
            ListNode tmp = curr.next.next;
            curr.next.next = curr;
            curr.next = tmp;
            
            curr = curr.next;
        }
        
        return newHead;
    }
}