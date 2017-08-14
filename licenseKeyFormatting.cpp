class Solution {
public:

string licenseKeyFormatting(string S, int K) {
      string res;
      for (auto i = S.rbegin(); i < S.rend(); i++)
        if (*i != '-') (res.size()%(K+1)-K? res : res+='-') += toupper(*i);
      return reverse(res.begin(), res.end()), res;
    }
    
/*

MY SOLUTION

    string licenseKeyFormatting(string S, int K) {
        
        int dashes = getNoOfDashes(S);
        
        int num_chars = S.size() - dashes;
        
        int r = num_chars % K;
        
        int newDashes = r != 0 ? num_chars / K : (num_chars / K - 1);
        
        cout << " newDashes: " << newDashes << endl;
        
        int newLength = num_chars + newDashes;
        
        
        string k(newLength, 'A');
        
        int endIndex1 = S.size() - 1;
        int endIndex2 = k.size() - 1;
        
        int count = 0;
        
        while(endIndex1 > -1 && endIndex2 > -1) {
            
            if(S[endIndex1] != '-') {
                
                k[endIndex2] = getTransform(S[endIndex1]);
                
                --endIndex1;
                --endIndex2;
                
                ++count;
            }
            else {
                
                --endIndex1;
            }
            
            
            if(count == K) {
                
                k[endIndex2] = '-';
                --endIndex2;
                
                count = 0;
            }
        }
        
        return k;
    }
    */
    
    char getTransform(char c) {
        
        char r = c;
        
        if(c >= 'a' && c <= 'z') {
            
            r = toupper(c);
        }
        
        return r;
    }
    
    
    int getNoOfDashes(string& S) {
        
        int dashes = 0;
        
        for(int index = 0; index < S.size(); index++) {
            
            if(S[index] == '-') {
                
                ++dashes;
            }
        }
        
        return dashes;
    }
};