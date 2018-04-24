class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int curr = 0;
        
        vector<int> currPath = {0};
        vector<vector<int>> paths;
        
        int vertices = 0;
        
        for(int row = 0; row < graph.size(); row++) {
            for(int neigh = 0; neigh < graph[row].size(); neigh++) {
                
                vertices = max(vertices, graph[row][neigh]);
            }
        }
        
        findPaths(curr, currPath, paths, graph, vertices);
        
        return paths;
    }
    
    void findPaths(
        int curr,
        vector<int>& currPath,
        vector<vector<int>>& paths,
        vector<vector<int>>& graph,
        int& N) {
        
        if(curr == N) {
            
            paths.push_back(currPath);
        }
        else {
            
            int row = curr;

            for(int col_neighbour = 0; col_neighbour < graph[row].size(); col_neighbour++) {
            
                int neigh = graph[row][col_neighbour];
                
                cout << col_neighbour << endl;
                cout << neigh << endl;
                
                currPath.push_back(graph[row][col_neighbour]);
                
                findPaths(graph[row][col_neighbour], currPath, paths,graph, N);
                
                currPath.pop_back();
            }
        }
    }
};