class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        bool found = false;
        int index1 = 0, index2 = 0;
        
        while(index1 < abbr.size() && index2 < word.size() && !found) {
            
            if(!isdigit(abbr[index1])) {
                
                found = !(abbr[index1] == word[index2]);
                
                /*if((abbr[index1] != word[index2])) {
                    
                    return false;
                }*/
                ++index1;
                ++index2;
            }
            else {
                
                if(abbr[index1] == '0') {
                    
                    return false;
                }
                
                int number = 0;
                /*while(index1 < abbr.size() && isdigit(abbr[index1])) {
                    
                    number = 10*number + abbr[index1] - '0';
                    ++index1;
                }*/
                
                
                
                string number_string;
                int end = findFirstLetter(abbr, index1, number_string);
                index1 = end;
                number = stoi(number_string);
                
                
                index2 += number;
            }
        }
        
        return !found && index1 == abbr.size() && index2 == word.size();
    }
    
    int findFirstLetter(string abbr, int start, string& number_string) {
        
        bool letterFound = false;
        
        int index1 = start;
        
        while(index1 < abbr.size() && !letterFound) {
            
            char c = abbr[index1];
            
            if(!isdigit(c)) {
                letterFound = true;
            }
            else {
                number_string.push_back(c);
                ++index1;
            }
        }
        
        return index1;
    }
    
    bool isLetter(char c) {
        
        return 'a' <= c && c <= 'z';
    }
};
