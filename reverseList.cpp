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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr) {
            
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        ListNode* curr = head;
        
        while(head != nullptr) {
            
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};