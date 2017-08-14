class Solution {
public:
    bool canWinNim(int n) {
        
        /*vector<bool> res(n);
        
        res[1] = true;
        res[2] = true;
        res[3] = true;
        
        for(int i = 4; i <= n; i++) {
            
            res[i] = !res[i-1] || !res[i-2] || !res[i-3];
        }*/
        
        return n % 4 != 0;
    }
    
    bool canWin(int n) {
        
        if(n >= 1 && n <= 3) {
            
            return true;
        }
        
        return !(canWin(n - 1) && canWin(n - 2) && canWin(n - 3));
    }
};