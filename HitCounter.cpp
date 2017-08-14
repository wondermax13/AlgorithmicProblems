class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        
        auto tpair = make_pair<>(timestamp, 1);
        
        auto it = lower_bound(
                    hits.begin(), hits.end(),
                    tpair,
                    [](const pair<int, int>& left, const pair<int, int>& right) -> bool {
                        
                        return left.first < right.first;
                    });
                    
        if(it == hits.end() || it->first != timestamp) {
            
            hits.insert(it, tpair);
        }
        else {
            
            it->second++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        
        if(hits.size() == 0) {
            
            return 0;
        }
        
        int searchStamp = max(timestamp - 299, 1);
        
        auto tpair = make_pair<>(searchStamp, 1);
        
        auto it = lower_bound(
                    hits.begin(), hits.end(),
                    tpair,
                    [](const pair<int, int>& left, const pair<int, int>& right) -> bool {
                        
                        return left.first < right.first;
                    });
        
        int count = 0;
        
        while(it != hits.end() && it->first <= timestamp) {
            
            //cout << " adding " << it->second << endl;
            count += (it->second);
            ++it;
        }
        
        return count;
    }
    
    vector<pair<int, int>> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */