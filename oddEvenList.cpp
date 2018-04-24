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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* odd = head;
        ListNode* even = nullptr;
        
        if(head != nullptr && head-> next != nullptr) {
            
            ListNode* evenHead = head->next;
            
            even = evenHead;
            
            while(odd->next != nullptr && odd->next->next != nullptr) {
                
                ListNode* evenNext = odd->next->next->next;
                
                odd->next = odd->next->next;
                odd = odd->next;
                
                even->next = evenNext;
                even = even->next;
            }
            
            odd -> next = evenHead;
        }
        
        return head;
    }
};