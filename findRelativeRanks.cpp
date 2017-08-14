class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> nums_copy_(nums);
        sort(nums_copy_.begin(), nums_copy_.end());
        
        vector<string> res(nums.size());
    
        for(int index = 0; index < nums.size(); index++) {
            
            auto it = find(nums_copy_.begin(),nums_copy_.end(), nums[index]);
            
            int dist = distance(nums_copy_.begin(), it);
            
            string rank = to_string(size - dist);
            if(dist == size - 1) {
                rank = "Gold Medal";
            }
            else if(dist == size - 2) {
                rank = "Silver Medal";
            }
            else if(dist == size - 3) {
                rank = "Bronze Medal";
            }
            
            res[index] = rank;
        }
        
        
        return res;
    }
};