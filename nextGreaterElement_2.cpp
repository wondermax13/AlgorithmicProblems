class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> res(nums.size(), -1);
        
        
        if(nums.size() <= 1) {
            
            //res[0] = -1;
            
            return res;
        }
        
        
        
        /* USING TRAVERSAL FOR EACH ELEMENT O(N^2)
           CANT USE START, END SINCE 8, 4, 6, 10 has different results for 8 and 4. So can't use 8 results for 4
        */
        int curr = 0;
        
        while(curr <= nums.size() - 1) {
            
            int index = curr < (nums.size() - 1) ? curr + 1 : 0;
            bool found = false;
            
            while(index != curr && !found) {
                
                found = nums[index] > nums[curr];
                
                if(!found) {
                    index = index < (nums.size() - 1) ? index + 1 : 0;
                }
            }
            
            res[curr] = found ? nums[index] : -1;
            
            ++curr;
        }
        
        return res;
    }
};class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        /*
            IDEAL SOLN.
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s; // index stack
        
        for (int i = 0; i < 2*n; i++) { //ITERATE OVER ALL THE INDICES TWICE (SINCE ROTATED)
        
            int num = nums[i % n]; 
            
            //IF THERE ARE PREVIOUS REMAINING INDICES IN THE STACK
            //SET THEIR NEXT TO CURR IF CURR IS GREATER THAN THEM
            //WE CAN ASSUME THAT THE LOWER VALUES WILL BE AT TOP AND HIGHER AT BOTTOM
            //OTHERWISE THE TOP HIGHER VALUES WOULD HAVE BEEN SET AS GREATER FOR THE BOTTOM LOWER  ONES
            while (!s.empty() && nums[s.top()] < num) { 
                next[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i); //IF 
        }   
        return next;
        */
        
        vector<int> res(nums.size(), -1);
        
        
        if(nums.size() <= 1) {
            
            //res[0] = -1;
            
            return res;
        }
        
        
        
        /* USING TRAVERSAL FOR EACH ELEMENT O(N^2)
           CANT USE START, END SINCE 8, 4, 6, 10 has different results for 8 and 4. So can't use 8 results for 4
        */
        int curr = 0;
        
        while(curr <= nums.size() - 1) {
            
            int index = curr < (nums.size() - 1) ? curr + 1 : 0;
            bool found = false;
            
            while(index != curr && !found) {
                
                found = nums[index] > nums[curr];
                
                if(!found) {
                    index = index < (nums.size() - 1) ? index + 1 : 0;
                }
            }
            
            res[curr] = found ? nums[index] : -1;
            
            ++curr;
        }
        
        return res;
    }
};