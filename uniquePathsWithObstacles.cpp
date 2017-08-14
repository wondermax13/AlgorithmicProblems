
/*
    CORRECT SOLUTION
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(),
            n = obstacleGrid[0].size();
        
        vector<vector<int>> noOfPaths(m, vector<int>(n));

        noOfPaths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                
                if(!(row == 0 && col == 0)) {
                if(obstacleGrid[row][col] == 1) {
                    
                    noOfPaths[row][col] = 0;
                }
                else {
                    
                    int top = row > 0 ? noOfPaths[row-1][col] : 0;
                    int left = col > 0 ? noOfPaths[row][col-1] : 0;
                    
                    noOfPaths[row][col] = top + left;
                }
                }
            }
        }

        return noOfPaths[m-1][n-1];
    }
};


/*
    1st ATTEMPT SOLUTION
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(),
            n = obstacleGrid[0].size();
        
        vector<vector<int>> noOfPaths(2, vector<int>(2));
        initNoOfPaths(obstacleGrid,noOfPaths,m,n);
        
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                
                if(obstacleGrid[row][col] == 1) {
                    
                    noOfPaths[row][col] = 0;
                }
                else {
                    
                    noOfPaths[row][col] = noOfPaths[row-1][col] + noOfPaths[row][col-1];
                }
            }
        }

        return noOfPaths[m-1][n-1];
    }
    
    void initNoOfPaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& noOfPaths, int m, int n) {
        
        int col = 0;
        while(col < n && obstacleGrid[0][col] == 0) {
            
            noOfPaths[0][col] = 1;
            ++col;
        }
        
        col += 1;
        while(col < n) {
            
            noOfPaths[0][col] = 0;
            ++col;
        }
        
        int row = 0;
        while(row < m && obstacleGrid[row][0] == 0) {
            
            noOfPaths[row][0] = 1;
            ++row;
        }
        
        row += 1;
        while(row < m) {
            
            noOfPaths[0][row] = 0;
            ++row;
        }
    }
};