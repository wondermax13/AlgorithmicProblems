class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex == 1) {
            
            vector<int>res = {1, 1};
            return res;
        }
        else if(rowIndex == 2) {
            
            vector<int>res = {1, 2, 1};
            return res;
        }
        
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        res[1] = 2;
        res[2] = 1;
        
        //Create kth row
        for(int k = 3; k <= rowIndex; k++) {
            
            int curr = 1, prev = 1;
            for(int index = 1; index < k + 1; index++) {
                
                curr = res[index];
                res[index] += prev;
                prev = curr;
            }
        }
        
        return res;
    }
};