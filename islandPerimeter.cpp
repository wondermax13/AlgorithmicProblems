class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        
        if(rows == 0) {
            
            return 0;
        }
        
        int cols = grid[0].size();
        
        if(rows == 1 && cols == 1) return 4;
        
        unordered_set<int> set_;
        
        // int firstIndex = findFirstIndex(grid, rows, cols);
        // set_.insert(firstIndex);
        
        bool noEntryFoundInRow = false;
        
        int row = 0; //getIndexRow(firstIndex, cols, rows);
        
        int perimeter = 0;
        
        int colsFound = 0; //Total 1 entries found
        int removeFromSides = 0; //Total neighbours with 1
        
        while(row < rows && !noEntryFoundInRow) {
            
            //Search all columns
            int currCol = 0; //getIndexCol(firstIndex, cols, rows);
            
            bool zeroFound = false;
            while(currCol < cols && !zeroFound) {
                
                if(grid[row][currCol] == 1) {
                    
                    int oneIndex = getIndex(row, currCol, rows, cols);
                    set_.insert(oneIndex);
                    
                    ++colsFound;

                    if(isOne(getIndex(row, currCol - 1, rows, cols), set_)) {
                        
                        ++removeFromSides;
                    }
                    if(isOne(getIndex(row - 1, currCol, rows, cols), set_)) {
                        
                        ++removeFromSides;
                    }
                    // perimeter += (4 - removeFromSides);
                }
                
                ++currCol;
            }
            // noEntryFoundInRow = colsFound == 0;
            ++row;
        }
        
        perimeter += (4*colsFound - 2*removeFromSides);
        
        return perimeter;
    }
    
    int findFirstIndex(vector<vector<int>>& grid, int rows, int cols) {
        
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                
                if(grid[row][col] == 1) {
                    
                    return getIndex(row, col, rows, cols);
                }
            }
        }
        
        return -1;
    }
    
    int getIndexRow(int index, int rowSize, int colSize) {
        
        return index / rowSize;
    }
    
    int getIndexCol(int index, int rowSize, int colSize) {
        
        return index % rowSize;
    }
    
    int getIndex(int row, int col, int rowSize, int colSize) {
        
        if(row < 0 || row > rowSize - 1 || col < 0 || col > colSize - 1 ) {
            
            return -1;
        }
        
        return (row - 1) * rowSize + col;
    }
    
    bool isOne(int index, unordered_set<int>& set_) {
        
        return set_.find(index) != set_.end();
    }
};