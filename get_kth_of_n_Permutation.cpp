class Solution {
public:
    string getPermutation(int n, int k) {
        
        string res, curr;
        
        int rem = 1;
        
        bt(curr, n, k, rem, res);
        
        return res;
    }
    
    string bt(string& curr, int n, int k, int& rem, string& res) {
        
        if(curr.size() == n) {
            if(rem == k) {
                
                res = curr;
            }
            else {
                ++rem;
            }
        }
        else {
            
            for(int i = 1; i <= n && res.empty(); i++) {
                
                if(curr.find(to_string(i)) == string::npos) {
                    
                    curr.append(to_string(i));
                    bt(curr, n, k, rem, res);
                    curr.pop_back();
                }
            }
        }
        
        return res;
    }
};


/*ITERATIVE SOLUTION*/
class Solution {
public:
    string getPermutation(int n, int k) {
        
        string res, curr;
        
        vector<int> nums(n, 1);
        for(int i = 1; i <= n; i++) {
            
            nums[i-1] = i;
        }
        
        
        int factorial[n + 1];
        factorial[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            
            factorial[i] = i * factorial[i-1];
        }
        
        int q, r, rem = k - 1, digits = n - 1;
        
        --k;
        
        for(int i = 1; i<= n; i++) {
            
            q = k / (factorial[n - i]);
            
            res.append(to_string(nums[q]));
            
            nums.erase(nums.begin() + q);
            
            k -= q * (factorial[n - i]);
        }
        

        return res;
    }
};
















