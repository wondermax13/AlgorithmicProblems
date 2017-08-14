class Solution {
public:
    int countSubstrings(string s) {
        
        int size = s.size();
        int count = 0;
        
        if(size > 0) {
        
        vector<vector<int>>P(size, vector<int>(size));
        
        for(int index = 0; index < size; index++) {
            
            P[index][index] = 1;
        }
        
        for(int len = 2; len <= size; len++) {
            
            for(int start = 0; start <= size - len; start++) {
                
                int end = start + len - 1;
                
                if(end - start == 1) {
                    
                    P[start][end] 
                        = s[start] == s[end] ? 1 : 0;
                    
                    cout << " start: " << start << " end: " << end << " " << P[start][end] << endl;
                }
                else {
                    
                    P[start][end] 
                        = (P[start+1][end-1] == 1
                        && s[start] == s[end]) ? 1 : 0;
                }
            }
        }
        
        for(int start = 0; start < size; start++) {
            for(int end = start; end < size; end++) {
            
                count += P[start][end];
            }
        }
        }
        
        return count;
    }
};