class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        
        
        vector<int> topThree;
        
        for(auto index : nums) {
            
            if(find(topThree.begin(), topThree.end(), index) == topThree.end()) {
            if(topThree.size() < 3) {
                
                topThree.push_back(index);
            }
            else {
                
                replaceMin(index, topThree);
            }
            }
        }
        
        int minIndex = 0;
        
        if(topThree.size() == 3) {
            
            minIndex = findMinIndex(topThree);
        }
        else {
            
            minIndex = findMaxIndex(topThree);
        }
        
        return topThree[minIndex];
    }
    
    void replaceMin(int newVal, vector<int>& vals) {
        
        int minIndex = findMinIndex(vals);
        
        if(vals[minIndex] <  newVal) {
            
            vals[minIndex] = newVal;
        }
    }
    
    int findMinIndex(vector<int>& vals) {
        
        
        
        int minIndex = 0;
        int minVal = vals[0];
        
        for(int index = 1; index < vals.size(); index++) {
            
            if(minVal > vals[index]) {
                
                minIndex = index;
                minVal = vals[index];
            }
        }
        
        // auto result= (min_element(vals.begin(), vals.end()));
        
        return minIndex; //*result;
    }
    

    int findMaxIndex(vector<int>& vals) {
        
        int minIndex = 0;
        int minVal = vals[0];
        
        for(int index = 1; index < vals.size(); index++) {
            
            if(minVal < vals[index]) {
                
                minIndex = index;
                minVal = vals[index];
            }
        }
        
        return minIndex;
    }
};