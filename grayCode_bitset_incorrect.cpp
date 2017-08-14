class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res;
        
        bitset<a> seq;
        
        bt_permute(1, seq, res, n);
    }
    
    template<int N>
    void bt_permute(int pos, bitset<N>& seq, vector<int>& res, int n) {
        
        if(pos >= n -1) {
            
            res.push_back(seq.to_ulong());
        }
        else {
            
            for(int i = 0; i <= 1; i++) {
                
                seq[pos+1] = i;
                bt_permute(pos + 1, seq, res, n);
                seq.pop_back();
            }
        }
    }
};