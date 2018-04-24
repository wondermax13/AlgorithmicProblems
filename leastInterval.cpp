class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int spaces = 0, placed = 0;
        
        vector<int> remains(26);
        
        unordered_map<char, int> last;
        
        for(auto task : tasks) {
            
            remains[task - 'A']++;
        }
        
        int index = 0, remainIndex = -1;
        
        while(placed < tasks.size()) {
            
            int tmp = remainIndex;
            remainIndex = findNextLetter(remainIndex, index, n, last, remains);
            
            cout << remainIndex << ' ' << endl;
            
            if(remainIndex == -1) {
                
                ++spaces;
                remainIndex = tmp;
                cout << " Not found " << endl;
            }
            else {
                
                ++placed;
                char letter = 'A' + remainIndex;
                last[letter] = index;
                remains[remainIndex]--;
                
                cout << letter << endl;
            }
            
            ++index;
        }
        
        
        return tasks.size() + spaces;
    }
    
    int findNextLetter(
        int remainIndex,
        int curr,
        int n,
        unordered_map<char, int> last,
        vector<int>& remains) {
        
        int res = -1;
        
        int index = (remainIndex == -1 || remainIndex == 25) ? 0 : remainIndex + 1;
        bool found = false;
        
        while(index != remainIndex && !found) {
            
            if(remains[index] != 0) {
                
                found = (last.find('A' + remainIndex) == last.end()
                        || last['A' + remainIndex] + n < curr);
            
                if(found) {
                
                    res = index;
                }
            }
                
            index = index == 25 ? 0 : index + 1;
        }
        
        
        return res;
    }
};