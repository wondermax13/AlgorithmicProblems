class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector <string> summary;
        
        if(!nums.empty()) {
            
            int index = 0, lastEntry = nums[index], firstEntry = lastEntry;
            
            string curr = to_string(firstEntry);
            
            index = 1;
            
            while(index < nums.size()) {
                
                if(nums[index] == lastEntry + 1) {
                    
                    lastEntry = nums[index];
                }
                else {
                    
                    appendLastEntryData(curr, firstEntry, lastEntry);
                    summary.push_back(curr);
                    
                    firstEntry = nums[index];
                    lastEntry = nums[index];
                    curr = to_string(lastEntry);
                }
                
                ++index;
            }
            
            appendLastEntryData(curr, firstEntry, lastEntry);
            
            summary.push_back(curr);
        }
        
        return summary;
    }
    
    void appendLastEntryData(string &curr, int firstEntry, int lastEntry) {
        
        if(firstEntry != lastEntry) {
                
                curr.append("->");
                curr.append(to_string(lastEntry));
        }
    }
};