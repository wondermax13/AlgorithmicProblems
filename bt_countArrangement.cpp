class Solution {
public:
    int countArrangement(int N) {
        
        
        int count = 0;
        
        string s(N + 1, '0');
        bitset<10> used_(s);
        
        tryPermute(used_, 1, count, N);
        
        return count;
    }
    
    void tryPermute(bitset<10>& used_, int currPosition, int& count, int N) {
        
        int size = used_.size();
        
        //Why can't this be used. We set N of the N + 1 zeros to 1
        /*if(used_.count() == size - 1) {
            
            count++;
        }*/
        if(currPosition > N) {
            
            count++;
        }
        else {
            
            for(int i = 1; i <= N; i++) {
                
                //Integer i hasn't been used yet
                if(used_[i] != 1) {
                    
                    if(i % currPosition == 0 || currPosition % i == 0) {
                        
                        used_[i] = true;
                        
                        //Recursive call
                        tryPermute(used_, currPosition + 1, count, N);
                        
                        used_[i] = false;
                    }
                }
            }
        }
    }
};
