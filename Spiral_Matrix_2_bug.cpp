class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> vec(n, vector<int>(n, 0));
        
        if(n == 0) {
            return vec;
        }
        
        if(n == 1) {
            vec[0][0] = 1;
            return vec;
        }
        
        int i = 0, j = 0, d = 0, curr = 1;
     
     while(curr < n);
     {   
        //1st step
        while(j <= (n-d-1)) {
            
            vec[i][j] = curr^2;
            ++curr;
            ++j;
        }
        ++i; --j;
        
        //2nd step
        while(i <= (n-d-1)) {
            
            vec[i][j] = curr^2;
            ++curr;
            ++i;
        }
        --i;--j;
        
        //3rd step
        while(j >= d) {
            
            vec[i][j] = curr^2;
            ++curr;
            --j;
        }
        --i; ++j;
        
        // d += 2;
        
        //4th step
        while(i >= d + 1) {
            
            vec[i][j] = curr^2;
            ++curr;
            --i;
        }
        ++i; ++j;
        
        ++d;
    }
        
        return vec;
    }
};