class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string res;
        
        if(strs.size() > 0) {
            string num_str = to_string(strs.size());
        
            res.insert(res.size(), num_str);
            res.push_back(' ');
        
            for(auto str : strs) {
            
                res.insert(res.size(), to_string(str.size()));
                res.push_back(' ');
            }
        
            for(auto str : strs) {
            
                res.insert(res.size(), str);
                //res.push_back(' ');
            }
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        vector<string> res;
        
        
        if(s.size() > 0) {
            
            string num_str;
            
            int index = 0;
            
            while(index < s.size() && s[index] != ' ') {
                
                num_str.push_back(s[index]);
                ++index;
            }
            ++index;
            
            int num = stoi(num_str);
            
            vector<int> sizes(num);
            
            for(int strIndex = 0; strIndex < num; strIndex++) {
                
                string num_str;
                while(index < s.size() && s[index] != ' ') {
                
                    num_str.push_back(s[index]);
                    ++index;
                }
                
                ++index;
                
                sizes[strIndex] = stoi(num_str);
            }
            
            for(int strIndex = 0; strIndex < num; strIndex++) {
                
                string curr;
                int len = sizes[strIndex];
                
                if(len > 0) {
                    
                    curr = s.substr(index, len);
                
                    index += sizes[strIndex];
                }
                
                res.push_back(curr);
            }
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));