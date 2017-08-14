class Solution {
public:
    string reverseVowels(string s) {
        
        vector<int> vowels;
        
        for(int index = 0; index < s.size(); index++) {
            
            if(isVowel(s[index])) {
                
                vowels.push_back(index);
            }
        }
        
        int start = 0, end = vowels.size() - 1;
        
        while(start < end) {
            
            swap(s[vowels[start]], s[vowels[end]]);
            
            ++start;
            --end;
        }
        
        return s;
    }
    
    bool isVowel(char c) {
        
        return c == 'a'
            || c == 'e'
            || c == 'i'
            || c == 'o'
            || c == 'u'
            || c == 'A'
            || c == 'E'
            || c == 'I'
            || c == 'O'
            || c == 'U';
    }
};