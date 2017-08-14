class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        int diff = INT_MAX;
        
        int q = -1;
        
        for(int index = 1; index <= sqrt(area); index++) {
            
            if(area % index == 0) {
                
                q = area / index;
                
                if(abs(q - index) < diff) {
                    
                   diff = abs(q - index); 
                }
            }
        }
        
        if(q == -1) {
            q = 1;
        }
        
        int index_ = area / q;
        
        vector<int> res;
        res.push_back(q);
        res.push_back(index_);
        
        return res;
    }
};