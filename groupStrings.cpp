class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<int> matched;
        vector<vector<string>> matches;
        
        unordered_map<string, vector<string>> uo_map;
        
        for(auto s : strings) {
            
            uo_map[getBitMap(s)].push_back(s);
        }
        
        for(auto mp : uo_map) {
            
            vector<string> matchList = mp.second;
            
            matches.push_back(matchList);
        }
        
        return matches;
    }
    
    string getBitMap(string& s) {
        
        int len = s.size();
        int arr[len];
        
        int offset = s[0] - 'a';
        
        string key(len, 'X');
        
        for(int i = 0; i < len; i++) {
            
            char c = (char)(s[i] - offset);
            if(c < 'a') {
                
                c += 26;
            }
            key[i] = c;
        }
        
        return key;
    }
};