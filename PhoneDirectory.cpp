class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : numbers(maxNumbers) {
        
        
        for(int i = 0; i < maxNumbers; i++) {
            
            numbers[i] = i;
        }
        
        num_used = 0;
        total_nums = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        
        int num = -1;
        if(num_used < total_nums) {
            
            bool found = false;
            int index = 0;
            while(index < total_nums && !found) {
                
/*                if(used.find(index) == used.end()) {
                
                    found = true;
                    num = index;
                    
                    used.insert(index);
                }*/
                
                if(numbers[index] != -1) {
                
                    found = true;
                    num = index;
                    
                    numbers[index] = -1;
                }
                
                ++index;
            }
            
            ++num_used;
        }
        
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        
        return numbers[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        
        if(numbers[number] == -1) {
            
            numbers[number] = number;
            --num_used;
        }
    }
    
    vector<int> numbers;
    // unordered_set<int> used;
    int num_used;
    int total_nums;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */