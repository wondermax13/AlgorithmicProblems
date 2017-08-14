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
        
        
        for(int len = 2; len < size; len++) {
            
            //Each move changes with the remaining array length
            p1_move = !p1_move;
            
            for(int startIndex = 0; startIndex + (len-1) < size; startIndex++) {
                
                int endIndex = startIndex + (len-1);
                
                int firstVal = T[startIndex][endIndex-1] + p1_move ? nums[endIndex] : -nums[endIndex];
                int secondVal = T[startIndex+1][endIndex] + p1_move ? nums[startIndex] : -nums[startIndex];
                
                T[startIndex][endIndex] = max(firstVal, secondVal);
            }
        }
        
        return T[0][size-1] > 0;
    }
};