class Solution {
public:
    int romanToInt(string s) {
     
        int res = 0;
        
        unordered_map<char, int> m({
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} });
        
        int index = 0;
        
        while(index < s.size()) {
            
            if(m[s[index + 1]] <= m[s[index]]) {
                
                res += m[s[index]];
                ++index;
            }
            else {
                
                int curr = index;
                int val = 0;
                while(curr < s.size() - 1 && m[s[curr + 1]] > m[s[curr]]) {
                    
                    val -= m[s[curr]];
                    ++curr;
                }
                
                val += m[s[curr]];
                
                res += val;
                
                index = curr + 1;
            }
        }
        
        return res;
    }
};