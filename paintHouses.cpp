class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        int rows = costs.size();
        
        if(rows == 0) {
            return 0;
        }
        
        vector<vector<int>> colors(rows, vector<int>(3));
        
        colors[0] = costs[0];
        
        for(int index = 1; index < rows; index++) {
            
            colors[index][0] = min(colors[index-1][1], colors[index-1][2]) + costs[index][0];
            colors[index][1] = min(colors[index-1][0], colors[index-1][2]) + costs[index][1];
            colors[index][2] = min(colors[index-1][0], colors[index-1][1]) + costs[index][2];
        }
        
        return min(colors[rows - 1][0], min(colors[rows - 1][1], colors[rows - 1][2]));
    }
};