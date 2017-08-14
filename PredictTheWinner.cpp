class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 0 | size == 1) {
            
            return true;
        }
        
        bool p1_move = (size % 2 == 1);
        
        vector<vector<int>> T(size, vector<int>(size));
        
        /*T.reserve(size);
        
        for(int index = 0; index < size; index++) {
            
            T[index].reserve(size);
        }*/
        
        for(int index = 0; index < size; index++) {
            
            T[index][index] = nums[index];
        }
        
        
        for(int len = 2; len-1 < size; len++) {
            
            for(int startIndex = 0; startIndex + (len-1) < size; startIndex++) {
                
                int endIndex = startIndex + (len-1);
                
                int firstVal = nums[endIndex] - T[startIndex][endIndex-1]; //P1 chose endIndex, P2 move
                int secondVal = nums[startIndex] - T[startIndex+1][endIndex]; //P1 chose startIndex, P2 move
                
                T[startIndex][endIndex] = max(firstVal, secondVal);
            }
        }
        
        return T[0][size-1] >= 0;
    }
};