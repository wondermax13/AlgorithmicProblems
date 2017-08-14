class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        vector<pair<int, int>> res(people.size());
        
        sort(people.begin(), people.end(),
            [](const pair<int, int>& left, const pair<int, int>& right) {
                
                return left.first < right.first
                    || (left.first == right.first && left.second < right.second);
            });
        
        createQueue(res, people);
        
        return res;
    }
    
    void createQueue(vector<pair<int, int>>& res, vector<pair<int, int>>& people) {
        
        vector<int> used(people.size(), 0);
        
        for(auto curr : people) {
            
            int passed = 0, rank = curr.second + 1, target = -1;
            
            int index = 0;
            bool found = false;
            
            while(index < people.size() && !found) {
                
                if(!used[index]) {
                    
                    ++passed;
                    
                    if(passed == rank) {
                    
                        found = true;
                        target = index;
                    
                        cout << " target: " << target << " for: " << curr.first << " and: " << curr.second << endl;
                    }
                }
                else {
                    
                    if(res[index].first >= curr.first) {
                        
                        ++passed;
                    }
                }
                
                ++index;
            }
            
            if(target != -1) {
                
                res[target] = curr;
                used[target] = 1;
            }
        }
    }
};