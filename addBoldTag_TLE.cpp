
/*

THESE NOTES IMPLY THAT WE CAN SEARCH EACH WORD IN DICT.

INSTEAD OF (1000*1000) combination substrings of the string

Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        
        unordered_set<string> set_;
        for(auto word : dict) {
            set_.insert(word);
        }
        
        vector<int> indices;
        populateIndices(s, indices, set_);
        
        for(auto ind : indices) {
            
            cout << " ind: " << ind << endl;
        }
        
        int newLen = s.size() + (7 * indices.size() / 2);
        cout << " newLen: " << newLen << endl;
        string result(newLen, 'a');
        
        /*
        int count = 0, newCount = 0, currentIndex = 0;
        bool open = true;
        while(newCount < result.size()) {
            
            //cout << " newCount: " << newCount << endl;
            if(!indices.empty() && indices[currentIndex] == count) {
                
                if(open) {
                    
                    result[newCount++] = '<';
                    result[newCount++] = 'b';
                    result[newCount++] = '>';
                    
                    if(count < s.size()) {
                        result[newCount++] = s[count];
                        
                        if(indices[currentIndex + 1] != count) {
                            
                            ++count;
                        }
                    }
                }
                else {
                    if(count < s.size()) {
                        result[newCount++] = s[count++];
                    }
                    
                    result[newCount++] = '<';
                    result[newCount++] = '/';
                    result[newCount++] = 'b';
                    result[newCount++] = '>';
                }
                
                open = !open;
                
                ++currentIndex;
            }
            else {
                
                if(count < s.size()) {
                        result[newCount++] = s[count++];
                }
            }
        }*/
        
        createResult(s, result, indices);
        
        
        return result;
    }
    
    void createResult(string& s, string& res, vector<int>& indices) {
        
        if(indices.empty()) {
            
            res = s;
        }
        else {
            
            int newIndex = 0, index = 0, additional = 0, currentIndex = 0;
            
            while(newIndex < res.size()) {
                
                if(currentIndex < indices.size()) {
                
                    while(newIndex - additional < indices[currentIndex]) {
                
                        res[newIndex] = s[newIndex - additional];
                
                        ++newIndex;
                    }
                
                    res[newIndex++] = '<';
                    res[newIndex++] = 'b';
                    res[newIndex++] = '>';
                
                    for(int i = indices[currentIndex]; i <= indices[currentIndex + 1]; i++) {
                    
                        res[newIndex++] = s[i];
                    }
                    
                    res[newIndex++] = '<';
                    res[newIndex++] = '/';
                    res[newIndex++] = 'b';
                    res[newIndex++] = '>';
                    
                    additional += 7;
                    currentIndex += 2;
                }
                else {
                    
                    res[newIndex] = s[newIndex - additional];
                    ++newIndex;
                }
            }
        }
    }
    
    void populateIndices(
        string& s, vector<int>& indices, unordered_set<string>& set_) {
        
        int size = s.size();
        
        for(int i = 0; i < size; i++) {
            
            for(int len = 1; len <= size - i; len++) {
                
                if(set_.find(s.substr(i, len)) != set_.end()) {
                    
                    if(!indices.empty() && indices.back() >= i - 1) {
                        
                        int curr = indices[indices.size() - 1];
                        indices[indices.size() - 1] = max(curr, i + len - 1);
                    }
                    else {
                        
                        indices.push_back(i);
                        indices.push_back(i + len - 1);
                    }
                }
            }
        }
    }
};