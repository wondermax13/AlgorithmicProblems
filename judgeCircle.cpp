class Solution {
public:
    
    bool judgeCircle(string moves) {
        
        bool found = false;
        
        int moveIndex = 0;
        
        int col = 0, row = 0;
        
        while(moveIndex < moves.size() && !found) {
            
            char move = moves[moveIndex];
            
            if(move == 'L') {
                --col;
            }
            if(move == 'R') {
                ++col;
            }
            if(move == 'D') {
                ++row;
            }
            if(move == 'U') {
                --row;
            }
            
            ++moveIndex;
        }
        
        found = (row == 0 && col == 0);
        
        
        return found;
    }
};