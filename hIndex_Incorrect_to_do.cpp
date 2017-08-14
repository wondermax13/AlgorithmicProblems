class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(citations.size() == 1 && citations[0] != 0) return 1;
        
        int maxC = 0;
        
        for(int cite : citations) {
            
            maxC = max(maxC, cite);
        }
        
        int cites[maxC + 1];
        for(int cite : citations) {
            
            cites[cite]++;
        }
        
        int total = citations.size(), i_plus_one_or_more = 0;
        int h_index = 0;
        
        for(int index = 1; index <= maxC; index++) {
            
            //Total papers with atleast index citations
            total -= cites[index - 1];
            i_plus_one_or_more = total - cites[index];
            
            if(total == index || i_plus_one_or_more == index) {
                
                h_index = index;
            }
        }
        
        return h_index;
    }
};