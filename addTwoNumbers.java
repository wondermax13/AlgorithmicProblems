/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        int quotient = 0,
            remainder = 0;
        
        ListNode curr = l1, prev = null, next;
        ListNode curr2 = l2, prev2 = null, next2;

        //REVERSE THE 2 LINKED LISTS        
        while(curr != null) {
            
            next = curr.next;
            
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        while(curr2 != null) {
            
            next2 = curr2.next;
            
            curr2.next = prev2;
            prev2 = curr2;
            curr2 = next2;
        }
        
        
        ListNode sumCurr = null;
        
        
        while(prev != null || prev2 != null) {
            
            int firstDigit = prev != null ? prev.val : 0,
                secondDigit = prev2 != null ? prev2.val : 0;
                
            remainder = (firstDigit + secondDigit + quotient) % 10;
            quotient = (firstDigit + secondDigit + quotient) / 10;
            
            sumCurr = addNode(sumCurr,remainder);
            
            if(prev != null) {
                
                prev = prev.next;
            }
            if(prev2 != null) {
                
                prev2 = prev2.next;
            }
        }
        
        
        if(prev == null && prev2 == null && quotient != 0) {
            
            sumCurr = this.addNode(sumCurr, quotient);
        }
        
        curr2 = sumCurr;
        while(curr2 != null) {
            
            next2 = curr2.next;
            
            curr2.next = prev2;
            prev2 = curr2;
            curr2 = next2;
        }

        return prev2;
    }
    
    protected ListNode addNode(ListNode sumCurr, int val) {
        
        if(sumCurr == null) {
            
            sumCurr = new ListNode(val);
        }
        
        else {
            
            ListNode tail = sumCurr;
            while(tail.next != null) {
                
                tail = tail.next;
            }
            
            tail.next = new ListNode(val);
        }
        
        return sumCurr;
    }
}
