class Solution {
public:
    int numberOfPatterns(int m, int n) {
        
        int count = 0;
        vector<int> curr;
        
        bt_permute(-1, curr, count, m, n);
        
        return count;
    }
    
    void bt_permute(int prevIndex, vector<int>& curr, int& count, int m, int n) {
        
        if(curr.size() <= n) {
            
            if(curr.size() >= m) {
                count++;
            }
            
            for(int index = 1; index <= 9; index++) {
                
                //Index not present in seq. till now
                if(find(curr.begin(), curr.end(), index) == curr.end()) {
                    
                    if(areValidConsecutiveDigits(prevIndex, index, curr)) {
                        
                        curr.emplace_back(index);
                        
                        bt_permute(index, curr, count, m, n);
                        
                        curr.pop_back();
                    }
                }
            }
        }
    }
    
    bool areValidConsecutiveDigits(int prevIndex, int index, vector<int>& curr) {
        
        if(prevIndex == -1 ) {
            
            return true;
        }
        
        //Not necessary
        if(prevIndex == index) {
            return false;
        }
        
        int prev_row = prevIndex / 3,
            prev_col = prevIndex % 3,
            row      = index / 3,
            col      = index % 3;
            
        if(prev_row == row && abs(col - prev_col) <= 1
            || prev_col == col && abs(row - prev_row) <= 1) {
            
            return true;
        }
        
/*        if((prevIndex == 1 && index == 6)
            || (prevIndex == 6 && index == 1)
            || (prevIndex == 1 && index == 8)
            || (prevIndex == 8 && index == 1)
            || (prevIndex == 2 && index == 7)
            || (prevIndex == 7 && index == 2)
            || (prevIndex == 2 && index == 9)
            || (prevIndex == 9 && index == 2)
            || (prevIndex == 3 && index == 4)
            || (prevIndex == 4 && index == 3)
            || (prevIndex == 3 && index == 8)
            || (prevIndex == 8 && index == 3)
            || (prevIndex == 4 && index == 9)
            || (prevIndex == 9 && index == 4)
            || (prevIndex == 6 && index == 7)
            || (prevIndex == 7 && index == 6)) {
                
                return true;
            }*/
            
        
        if((prevIndex == 1 && index == 3)
            || (prevIndex == 3 && index == 1)
            || (prevIndex == 1 && index == 7)
            || (prevIndex == 7 && index == 1)
            || (prevIndex == 2 && index == 8)
            || (prevIndex == 8 && index == 2)
            || (prevIndex == 3 && index == 1)
            || (prevIndex == 1 && index == 3)
            || (prevIndex == 4 && index == 6)
            || (prevIndex == 6 && index == 4)
            || (prevIndex == 7 && index == 9)
            || (prevIndex == 9 && index == 7)) {
                
        int mid_row = (prev_row + row) / 2,
            mid_col = (prev_col + col) / 2;
            
        int mid_index = (mid_row)*3 + mid_col;
        
        return (find(curr.begin(), curr.end(),mid_index) != curr.end());
            }
            
            
            return true;
    }
};