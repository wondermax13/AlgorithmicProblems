class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> lists;
        vector<int> curr;
        
        bt_c(n, curr, lists, 1);
        
        return lists;
    }
    
    void bt_c(int num, vector<int>& curr, vector<vector<int>>& lists, int prevNum) {
        
        if(num == 1) {
            if(!curr.empty()) {
            
                lists.emplace_back(curr);
            }
        }
        
        int start = prevNum != 1 ? prevNum : 2;
        
        //We can't use num as a factor only in the top call
        //Otherwise we have to use num as a factor in all the recurrence instance
        int end = prevNum != 1 ? num : num / start;
        
        
        //start - num since we have to reach num to use the whole list
        for(int i = start; i <= end; i++) {
            
            if(num % i == 0) {
                
                curr.push_back(i);
                bt_c( num / i, curr, lists, i);
                curr.pop_back();
            }
        }
    }
};