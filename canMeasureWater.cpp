class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
/*        int maxVal = max(x, max(y, z));
        
        vector<bool> T(maxVal + 1, false);
        T[0] = true;
        T[x] = true;
        T[y] = true;
        
        for(int i = 0; i < T.size(); i++) {
            
            if(i + x < T.size() && T[i]) {
            
                T[i + x] = true;
            }
            if(i - x > -1 && T[i]) {
            
                T[i - x] = true;
            }
        }
        
        for(int i = 0; i < T.size(); i++) {
            
            if(i + y < T.size() && T[i]) {
            
                T[i + y] = true;
            }
            if(i - y > -1 && T[i]) {
            
                T[i - y] = true;
            }
        }
        
        return T[z];*/
        
        if(z > x + y) return false;
        
        if(z == x+ y || z == x || z == y) return true;
    
        return z%GCD(x, y) == 0;
    }

    int GCD(int a, int b){
    
        while(b != 0 ){
            int temp = b;
            b = a%b;
            a = temp;
        }
        
        return a;
    }
};