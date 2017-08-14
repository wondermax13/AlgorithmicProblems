class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> nums;
        
        string init_string = "";
        string n_string = to_string(n);
        int m = n_string.size();
        
        findNext(init_string, n, m, nums);
        
        return nums;
    }
    
    void findNext(string num_string, int x, int m, vector<int>& nums) {
        
        if(num_string.size() < m) {
            
            int i_start = num_string.size() > 0 ? 0 : 1;
            
            bool passed = false;
            
            int i = i_start;
            while(i <= 9 && !passed) {
                
                num_string += ('0' + i);
                
                int num = stoi(num_string);
                if(num <= x) {
                    
                    nums.push_back(num);
                    
                    findNext(num_string, x, m, nums);
                }
                else {
                    passed = true;
                }
                
                num_string.pop_back();
                
                ++i;
            }
        }
    }
};