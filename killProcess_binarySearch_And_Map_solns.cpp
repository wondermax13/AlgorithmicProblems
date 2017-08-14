class Solution {
public:
    vector<int> killProcess(
        vector<int>& pid, vector<int>& ppid, int kill) {
        
        vector<int> res;
        deque<int> s;
        
        map<int, vector<int>> m;
        
        // sortBasedOnPpids(pid, ppid);
        
        generateMap(m, pid,ppid);
        
        s.push_back(kill);
        
        int count = 0;
        
        while(!s.empty()) {
            
            vector<int> children;
            int kill_pid_ = s.front();
            s.pop_front();
            
            res.push_back(kill_pid_);
            
            
            //findChildren(kill_pid_, pid, ppid, children);
            auto iter = m.find(kill_pid_);
            
            if(iter != m.end()) {
                for(auto child : iter->second) {
                
                    s.push_back(child);
                }
            }
            ++count;
        }
        
        return res;
    }
    
    void generateMap(map<int, vector<int>>& m, vector<int>& pid, vector<int>& ppid) {
        
        for(int index = 0; index < ppid.size(); index++) {
            
            m[ppid[index]].push_back(pid[index]);
        }
    }
    
    void sortBasedOnPpids(vector<int>& pid, vector<int>& ppid) {
        
        /*sort(pid.begin(), pid.end(), [ppid] (int left, int right) {
            
            return ppid[left] < 
        });
        */
        
        for(int start = 0; start < ppid.size(); start++) {
            
            int min_val = ppid[start], target = start;
            for(int index = start + 1; index < ppid.size(); index++) {
                
                if(ppid[index] < min_val) {
                    
                    min_val = ppid[index];
                    target = index;
                }
            }
            
            swap(ppid[start], ppid[target]);
            swap(pid[start], pid[target]);
        }
    }
    
    void findChildren(
        int kill_pid_, vector<int>& pid, vector<int>& ppid, vector<int>& children) {
        
        auto range_ = equal_range(ppid.begin(), ppid.end(), kill_pid_);
        
        for(auto iter = range_.first; iter != range_.second; iter++) {
            
            children.push_back(pid[distance(ppid.begin(), iter)]);
        }
/*        
        for(int index = 0; index < ppid.size(); index++) {
            
            if(ppid[index] == kill_pid_) {
                
                
            }
        }*/
    }
};