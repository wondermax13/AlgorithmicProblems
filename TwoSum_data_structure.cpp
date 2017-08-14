class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        
        auto it = freq.find(number);
        
        if(it != freq.end()) {
            
            freq[number]++;
            /*int count = it->second;
            it->second = count + 1;*/
        }
        else {
            
            freq[number] = 1;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        bool found = false;
        auto it = freq.begin();
        
        while(it != freq.end() && !found) {
            
            if(value % 2 == 0 && it-> first == (value/2)) {
                
                found = it-> second > 1;
            }
            else {
                
                found = freq.find(value - it->first) != freq.end();
            }
            
            ++it;
        }
        
        return found;
    }
    
    unordered_map<int, int> freq;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */