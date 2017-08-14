class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        //O(N)
        //F(k + 1) = F(k) + Bk+1[0]  = F(k) + A[k+1]
        
        int allSum = 0;
        int len = A.size();
        int F = 0;
        for (int i = 0; i < len; i++) {
            F += i * A[i];
            allSum += A[i];
        }
        int res = F;
        for (int i = len - 1; i >= 1; i--) {
            F = F + allSum - len * A[i];
            res = max(F, res);
        }
        return res;
        
        /* O(N^2) solution
        if(A.size() == 0) return 0;
        int res = INT_MIN;
        
        vector<int> f(A.size());
        
        for(int index = 0; index < A.size(); index++) {
            
            for(int func = 0; func < f.size(); func++) {
            
                f[func] += (((index + func) % (A.size())) * A[index]);
            }
        }
        
        for(int index = 0; index < A.size(); index++) {
            
            
            res = max(res, f[index]);
        }
        
        return res;
        */
    }
};