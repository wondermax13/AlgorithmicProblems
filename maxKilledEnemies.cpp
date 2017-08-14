class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        
        if(grid.size() == 0 || grid[0].size() == 0) {
            
            return 0;
        }
        
        int maxKills = 0;
        
        //vector<vector<int>> kills(grid.size(), vector<int>(grid[0].size()));
        
        //USE THIS INSTEAD OF KILLS GRID TO SAVE SPACE
        vector<int> colKills(grid[0].size());
        
        
        for(int i = 0; i < grid.size(); i++) {
            
            int colKill = 0, rowKill = 0;
            int endRowIndex, endColIndex;
            
            for(int j = 0; j < grid[0].size(); j++) {
                
                cout << "i : " << i << " j : " << j << endl;
                
                if(j == 0 || grid[i][j-1] == 'W') {
                    
                    endRowIndex = getRowKills(grid, i, j, rowKill);
                    
                    cout << " rowKill: " << rowKill << endl;
                    //populateRowKills(grid, i, j, endRowIndex, rowKill);, kills);
                }
                if(i == 0 || grid[i-1][j] == 'W') {
                    
                    endColIndex = getColKills(grid, i, j, colKill);
                    
                    //cout << " endColIndex: " << endColIndex << endl;
                    
                    //populateColKills(grid, i, j, endColIndex, colKill, colKills);kills);
                    
                    colKills[j] = colKill;
                    
                    cout << " colKills[" << j << "] = " << colKill << endl;
                }
                
                if(grid[i][j] == '0') {
                    maxKills = max(maxKills, rowKill + colKills[j]);
                    
                    cout << " maxKills: " << maxKills << endl;
                }
            }
        }
        
        //updateMaxKills(grid, maxKills, kills);
        
        return maxKills;
    }
    
    int getRowKills(vector<vector<char>> grid, int i, int j, int& rowKill) {
        
        int rowKills = 0;
        
        while(j < grid[0].size() && grid[i][j] != 'W') {
            
            if(grid[i][j] == 'E') {
                
                ++rowKills;
            }
            
            ++j;
        }
        
        rowKill = rowKills;
        
        return j - 1;
    }
    
    int getColKills(vector<vector<char>> grid, int i, int j, int& colKill) {
        
        int colKills = 0;
        
        while(i < grid.size() && grid[i][j] != 'W') {
            
            //cout << "i getColKills: " << i << endl;
            
            if(grid[i][j] == 'E') {
                
                ++colKills;
            }
            
            ++i;
        }
        
        colKill = colKills;
        
        return i - 1;
    }
    
    void populateRowKills(
        vector<vector<char>> grid,
        int i, int j, int rowIndex,
        int rowKill,
        vector<vector<int>>& kills) {
            
            for(int k = j; k <= rowIndex; k++) {
                
                if(grid[i][k] == '0') {
                    
                    kills[i][k] += rowKill;
                }
            }
    }
    
    void populateColKills(
        vector<vector<char>> grid,
        int i, int j, int colIndex,
        int colKill,
        vector<vector<int>>& kills) {
            
            for(int k = i; k <= colIndex; k++) {
                
                if(grid[k][j] == '0') {
                    
                    kills[k][j] += colKill;
                }
            }
    }

    void updateMaxKills(
        vector<vector<char>>& grid, int& maxKills, vector<vector<int>>& kills) {
        
        for(int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j] != 'E' && grid[i][j] != 'W') {
                    
                    maxKills = max(maxKills, kills[i][j]);
                }
            }
        }
    }
};

    void updateRowKills(vector<vector<char>>& grid, vector<vector<int>>& kills) {
        
        for(int i = 0; i < grid.size(); i++) {
            
            int rowKill = 0;
            int start = 0;
            
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j] == 'E') {
                    
                    ++rowKill;
                    
                }
                else if(grid[i][j] == 'W') {
                    
                    cout << " start: " << start << endl;
                    
                    for(int k = start; k < j; k++) {
                        
                        if(grid[i][k] == '0') {
                            
                            kills[i][k] += rowKill;
                        }
                    }
                    
                    start = j + 1;
                    rowKill = 0;
                    
                }
                else {
                    // kills[i][j] += rowKill;
                }
            }
        }
    }
    
    void updateColKills(vector<vector<char>>& grid, vector<vector<int>>& kills) {
        
        for(int i = 0; i < grid[0].size(); i++) {
            
            int rowKill = 0;
            int start = 0;
            
            for(int j = 0; j < grid.size(); j++) {
                
                if(grid[j][i] == 'E') {
                    
                    ++rowKill;
                    
                }
                else if(grid[j][i] == 'W') {
                    
                    cout << " start: " << start << endl;
                    
                    for(int k = start; k < j; k++) {
                        
                        if(grid[k][i] == '0') {
                            
                            kills[k][i] += rowKill;
                        }
                    }
                    
                    start = j + 1;
                    rowKill = 0;
                }
                else {
                    //kills[j][i] += rowKill;
                }
            }
        }
    }