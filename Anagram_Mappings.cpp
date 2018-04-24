class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        
        vector<int> res(A.size());
        
        unordered_set<int> used_;
        
        int a_index = 0;
        
        
        while(a_index < A.size()) {
            
            bool found = false;
            
            int b_index = 0;
            
            while(b_index < B.size() && !found) {
                
                if((used_.find(b_index) == used_.end())
                   && A[a_index] == B[b_index]) {
                    
                    found = true;
                    res[a_index] = b_index;
                    
                    used_.insert(b_index);
                }
                
                ++b_index;
            }
            
            a_index++;
        }
        
        return res;
    }
};