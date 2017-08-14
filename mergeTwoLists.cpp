/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        auto l1_ = l1;
        auto l2_ = l2;
        
        ListNode dummy(-1);
        auto curr = &(dummy);
        auto head = curr->next;
        
        while(l1_ && l2_) {
            
            int val;
            
            int val1 = l1_-> val;
            int val2 = l2_-> val;
            
            if(val1 < val2) {
                
                curr->next = l1_;
                l1_ = l1_-> next;
            }
            else {
                curr->next = l2_;
                l2_ = l2_-> next;
            }
            
            curr = curr -> next;
        }
        
        curr->next = l1_ ? l1_ : l2_;

        return dummy.next;
    }
};