
//Using std::partial_sort call
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        std::partial_sort(nums.begin(), nums.begin() + k, nums.end(),
        [] (const int &l, const int &r) {
                
                return l > r;
            });
        
        return *(nums.begin() + k - 1);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        std::priority_queue<int> q;
        std::vector<int> vec;
        int top;
        
        // q.push(nums[0]);
        
        for(int ele=0; ele < nums.size(); ele++) {
            
            if(q.size() < k) {
                
                //Add new element
                q.push(nums[ele]);
            }
            else {
                
                int elements = 0;
                while(elements < k-1) {
                    
                    vec.push_back(q.top());
                    elements++;
                    q.pop();
                }
                
                top = q.top();
                if(top < nums[ele]) {
                    
                    //Replace top element
                    q.pop();
                    q.push(nums[ele]);
                }
                
                elements = k-2;
                while(elements > -1) {
                    
                    //Add back all the elements
                    q.push(vec[elements]);
                    elements--;
                }
                // return q.top();
            }
        }
        
/*        int noOfEle = 0;
        while(noOfEle < k-1) {
            
            q.pop();
            noOfEle++;
        }
        
        // q.pop();
        // q.pop();
        int top = q.top();
*/        
        return q.top();
    }
};