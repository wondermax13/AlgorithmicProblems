class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool found = false;
        
        if(matrix.size() > 0 && matrix[0].size() > 0) {
        
            int cols = matrix[0].size();
            
            int row = 0, col = cols - 1;
            while(row >= 0 && row < matrix.size() && col >= 0 && col < cols && !found) {
            
                
                if(matrix[row][col] == target) {
                    
                    found = true;
                }
                else if(matrix[row][col] > target) {
                    
                    --col;
                }
                else {
                    
                    ++row;
                }
            }
        }
        
        return found;
    }
    
    /*
    bool doubleBinarySearch(
        int startRow, int endRow,
        int startCol, int endCol,
        vector<vector<int>>& matrix, int target) {
        
        bool found = false;
        
        while(startRow <= endRow && startCol <= endCol && !found) {
            
            int midRow = (startRow + endRow) / 2;
            int midCol = (startCol + endCol) / 2;
            
            if(matrix[startRow][mid] == target) {
                found = true;
            }
            else if(matrix[row][mid] > target) {
                
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        
        return matrix[startRow][startCol] == target;
    }*/
    
    bool binarySearch(int row, vector<vector<int>>& matrix, int target) {
        
        bool found = false;
        int cols = matrix[0].size();
        
        int start = 0, end = cols - 1;
        
        while(start <= end && !found) {
            
            int mid = (start + end) / 2;
            if(matrix[row][mid] == target) {
                found = true;
            }
            else if(matrix[row][mid] > target) {
                
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        
        return found;
    }
};