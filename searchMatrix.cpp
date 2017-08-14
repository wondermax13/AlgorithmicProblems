class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0) return false;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        int startIndex = 0, endIndex = rows*cols - 1;
        
        bool found = false;
        while(startIndex <= endIndex && !found) {
            
            int pivot = (startIndex + endIndex)/2;
            int mid = matrix[pivot/cols][pivot%cols];
            
            
            if(matrix[pivot/cols][pivot%cols] == target) {
                
                found = true;
            }
            else if(matrix[pivot/cols][pivot%cols] < target) {
                
                startIndex = pivot + 1;
            }
            else {
                
                endIndex = pivot - 1;
            }
        }
        
        return found;
    }
};