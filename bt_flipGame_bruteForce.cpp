class Solution {
public:
    bool canWin(string s) {
        
        if(s.size() == 0) {
            return false;
        }
        
        bool win = false;
        int player = 1;
        
        string c(s);
        
        return tryPermute(player,win, c);
        
        //win;
    }
    
    bool tryPermute(int& player, bool& win, string& s) {
        
        bool moveFound = false;
        bool won = false;
        
        for(int i = 0; i < s.size() - 1; i++) {
            
            //Move found for current player
            if(s[i] == '+' && s[i+1] == '+') {
                
                moveFound = true;
                
                s[i] = '-';
                s[i+1] = '-';
                // player = player == 1 ? 2 : 1;
                
                if(!tryPermute(player, win, s)) {
                    won = true;
                }
                
                s[i] = '+';
                s[i+1] = '+';
                player = player == 1 ? 2 : 1;
                
                if(won) {
                    return true;
                }
            }
        }
        
        
        //Check at the end
/*        if(player == 2 && !moveFound) {
            
            win = true;
        }*/
        
        return false;
    }
};