class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res;
        
        bitset<32> set_(n);
        
        string str = set_.to_string();
        
        int start = 0, end = 31;
        
        while(start < end) {
            
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
                
            ++start;
            --end;
        }
        
        bitset<32> new_set_(str);
        
        long l = new_set_.to_ulong();
        
        return (uint32_t)l;
    }
};