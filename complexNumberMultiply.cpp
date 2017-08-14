class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        
        int plus1 = a.find('+');
        int i1 = a.find('i');
        string r1_s_ = a.substr(0, plus1);
        string c1_s_ = a.substr(plus1 + 1, i1 - plus1);
        
        int plus2 = b.find('+');
        int i2 = b.find('i');
        string r2_s_ = b.substr(0, plus2);
        string c2_s_ = b.substr(plus2 + 1, i2 - plus2);
        
        int r1 = stoi(r1_s_);
        int c1 = stoi(c1_s_);
        int r2 = stoi(r2_s_);
        int c2 = stoi(c2_s_);
        
        int r_res_ = r1*r2 - c1*c2;
        int c_res_ = r1*c2 + r2*c1;
        
        string result = to_string(r_res_) + "+" + to_string(c_res_) + "i";
        
        return result;
    }
};