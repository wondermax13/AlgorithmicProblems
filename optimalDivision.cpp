class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        
        string s;
        
        if(nums.size() == 0) {
            
            return s;
        }
        
        if(nums.size() == 1) {
            
            s.append(to_string(nums[0]));
            return s;
        }
        
        else {
            
            s.append(to_string(nums[0]));
            
            s += ('/');
            
            if(nums.size() != 2) {
                s += ('(');
            }
            
            int index = 1;
        
            while(index < nums.size()) {
            
                
                s.append(to_string(nums[index]));
                
                if(index < nums.size() - 1) {
                    
                    s += ('/');
                }
            
                ++index;
            }
        
            if(nums.size() != 2) {
                s += (')');
            }
        }
        
        return s;
    }
};