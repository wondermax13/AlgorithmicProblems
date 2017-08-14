class Solution {
public:
    int numDistinct(string s, string t) {
        
        int t_size = t.size();
        
        vector<vector<int>>indices(t_size);
        
        for(int t_index = 0; t_index < t_size; t_index++) {
            for(int s_index = 0;  s_index < s.size(); s_index++) {
                
                if(s[s_index] == t[t_index]) {
                    
                    indices[t_index].push_back(s_index);
                }
            }
        }
        
        int lastIndex = -1;
        int count = 0;
        
        recurse(-1, indices, lastIndex, count);
        
        return count;
    }
    
    void recurse(
        int t_index, vector<vector<int>>& indices, int& lastIndex, int& count) {
        
        //cout << " t_index: " << t_index << " lastIndex: " << lastIndex << endl;
            
        if(t_index == indices.size() - 1) {
            
            ++count;
        }
        else {
            int prevLastIndex = lastIndex;
            
            for(int pos = 0; pos < indices[t_index+1].size(); pos++) {
                
                // cout << " pos: " << pos << endl;
                
                
                if(indices[t_index + 1][pos] > lastIndex) {
                    
                    //cout << " indices[t_index + 1][pos]: " << indices[t_index + 1][pos] << endl;
                    
                    lastIndex = indices[t_index + 1][pos];
                    recurse(t_index + 1, indices, lastIndex, count);
                    lastIndex = prevLastIndex;
                }
            }
        }
    }
};