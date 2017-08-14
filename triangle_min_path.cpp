class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        
        if(rows == 0) {
            
            return 0;
        }
        
        int cols = triangle[rows-1].size();
        
        vector<vector<int>> vals(rows, vector<int>(cols, INT_MAX));
        
        vals[0][0] = triangle[0][0];
        
        for(int row = 1; row < rows; row++) {
            
            for(int col = 0; col < triangle[row].size(); col++) {
                
                int leftVal = col > 0 ? vals[row-1][col-1] : INT_MAX;
                int rightVal = col < vals[row].size() - 1 ? vals[row-1][col+1] : INT_MAX;
                
                vals[row][col] = min(leftVal, rightVal) + triangle[row][col];
            }
        }
        
        int path = INT_MAX;
        
        for(int col = 0; col < cols; col++) {
            
            path = min(path, vals[rows-1][col]);
        }
        
        return path; //vals[rows-1][cols-1];
    }
};

/*

CORRECT DP SOLUTION

*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        
        if(rows == 0) {
            
            return 0;
        }
        
        int cols = triangle[rows-1].size();
        
        vector<int> vals(cols);
        
        for(int col = 0; col < triangle[rows - 1].size(); col++) {
            
            vals[col] = triangle[rows - 1][col];
        }
        
        for(int row = rows-2; row >= 0; row--) {
            
            for(int col = 0; col < triangle[row].size(); col++) {
                
                vals[col] = min(vals[col], vals[col + 1]) + triangle[row][col];
            }
        }
        
        return vals[0];
    }
};






