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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        
        num_nodes = 0;
        head_ptr = head;
        ListNode* curr = head;
        
        while(curr != nullptr) {
            
            ++num_nodes;
            
            curr = curr->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        int rn = rand() % num_nodes;
        
        cout << " rn: " << rn << endl;
        
        ListNode* curr = head_ptr;
        
        while(rn > 0) {
            
            --rn;
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    int num_nodes;
    ListNode* head_ptr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */