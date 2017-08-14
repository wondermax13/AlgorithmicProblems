class Solution {
public:
    int findLUSlength(string a, string b) {
        
        return a == b ? -1 : max(a.size(), b.size());
        
/*        int a_size_ = a.size();
        int b_size_ = b.size();
        
        vector<vector<int>> grid(a_size_, vector<int>(b_size_));
        
        int count = 0;
        for(int b_index_= 0; b_index_ < b_size_; b_index_++) {
            
            if(a[0] != b[b_index_]) {
                
                ++count;
                grid[0][b_index_] = count;
            }
        }
        
        count = 0;
        for(int a_index_= 0; a_index_ < a_size_; a_index_++) {
            
            if(b[0] != a[a_index_]) {
                
                ++count;
                grid[a_index_][0] = count;
            }
        }
        
        for(int a_index_= 1; a_index_ < a_size_; a_index_++) {
            for(int b_index_= 1; b_index_ < b_size_; b_index_++) {
                
                int add_ = b[b_index_] != a[a_index_] ? 1 : 0;
                
                grid[a_index_][b_index_] = min(grid[a_index_-1][b_index_], grid[a_index_][b_index_-1]) + add_;
            }
        }
        
        return grid[a.size() - 1][b.size() - 1];*/
    }
};