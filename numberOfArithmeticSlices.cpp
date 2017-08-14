class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int size = A.size();
        if(size < 3) {
            
            return 0;
        }
        
        vector<int> num(size);
        
        // num[2] = A[1] == (A[2] + A[0])/2 ? 1 : 0;
        
        int curr = 0, sum = 0;
        
        for(int index = 2; index < size; index++) {
            
            if(A[index-1] - A[index-2] == A[index] + A[index-1]) {
                
                curr += 1;
                sum += curr;
            }
            else {
                curr = 0;
            }
        }
        
        return sum;
    }
};