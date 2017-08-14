class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int majors[2];
        int counts[2];
        vector<int> res;
        
        if(nums.empty()) {
            
            return res;
        }
        
/*        if(nums.size() == 1) {
            
            res.push_back(nums[0]);
            
            return res;
        }
        
        if(nums.size() == 2) {
            
            res.push_back(nums[0]);
            res.push_back(nums[1]);
            
            return res;
        }*/
        
        majors[0] = nums[0];
        counts[0] = 0;
        
        majors[1] = nums[0];
        counts[1] = 0;
        
        for(int index = 0; index < nums.size(); index++) {
            
            int num = nums[index];
            
            if(num == majors[0]) {
                counts[0]++;
            }
            else if(num == majors[1]) {
                counts[1]++;
            }
            else if(counts[0] == 0) {
                
                majors[0] = num;
                counts[0] = 1;
            }
            else if(counts[1] == 0) {
                
                majors[1] = num;
                counts[1] = 1;
            }
            else {
                
                counts[0]--;
                counts[1]--;
            }
        }
        
        int count0 = 0, count1 = 0;
        
        for(auto num : nums) {
            
            if(num == majors[0]) {
                
                ++count0;
            }
            if(num == majors[1]) {
                
                ++count1;
            }
        }
        
        if(count0 > nums.size()/3) {
            
            res.push_back(majors[0]);
        }
        if(count1 > nums.size()/3 && (majors[0] != majors[1])) {
            
            res.push_back(majors[1]);
        }
        
        return res;
    }
};