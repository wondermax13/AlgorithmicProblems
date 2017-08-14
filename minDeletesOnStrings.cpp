class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int commonSubstr = findLongestCommonSubstr(word1, word2);
        
        return word1.size() + word2.size() - 2*commonSubstr;
    }
    
    int findLongestCommonSubstr(string& word1, string& word2) {
        
        int m = word1.size(), n = word2.size();
        
        vector<vector<int>> L(m + 1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(word1[i-1] == word2[j-1]) {
                    
                    L[i][j] = 1 + L[i-1][j-1];
                    
                    cout << " c: " << word2[j-1] << " " << L[i][j] << endl;
                }
                else {
                    
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
            }
        }
        
        return L[m][n];
    }
        
        
        
        
        
    
    int checkMatches(string& s1, string& s2) {
        
        cout << " s1: " << s1 << endl;
        cout << " s2: " << s2 << endl;
        
        if(s1.size() == 0) {
            
            return s2.size();
        }
        
        if(s2.size() == 0) {
            
            return s1.size();
        }
        
        if(s1 == s2) {
            return 0;
        }
        
        int minD = INT_MAX;
        for(int i = 0; i < s1.size(); i++) {
            
            cout << " i: " << i << endl;
            char c = s1[i];
            s1.erase(i, 1);
            
            int val = checkMatches(s1, s2);
            
            if(val != INT_MAX) {
                
                //cout << " val: " << val << endl;
                minD = min(minD, 1 + val);
            }
            string str(1, c);
            s1.insert(s1.begin(), c);
            
            cout << " after insert : " << s1 << endl;
        }
        
        for(int j = 0; j < s2.size(); j++) {
            
            cout << " j: " << j << endl;
            
            char c = s2[j];
            s2.erase(j, 1);
            
            int val = checkMatches(s1, s2);
            
            if(val != INT_MAX) {
                
                minD = min(minD, 1 + val);
            }
            string str(1, c);
            s2.insert(j, str);
        }
        
        if(minD != INT_MAX) {
                
                cout << " minD: " << minD << endl;
        }
        
        return minD;
    }
};