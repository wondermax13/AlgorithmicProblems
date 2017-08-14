class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        vector<string> res, curr(1, "JFK");
        
        //map<string, priority_queue<string, vector<string>, less<string> > > m;
        
        map<string, multiset<string> > m;
        
        for(auto ticket : tickets) {
            
            m[ticket.first].insert(ticket.second);
        }
        
        //int noUsed = 0;
        //vector<int> used(tickets.size());
        
        //findIter("JFK", noUsed, used, tickets, curr, res);
        
        visit("JFK", res, 0, m);
        
        return vector<string>(res.rbegin(), res.rend());
    }
    
    void visit(
        string src, vector<string> & res, int size,
        map<string, multiset<string> >& m) {
        
        cout << " src: " << src << endl;
            while(m[src].size()) {
                
                string next = *(m[src].begin());
                
                cout << " next: " << next << endl;
                
                m[src].erase(m[src].begin());
                visit(next, res, size, m);
            }
        
        res.push_back(src);
    }
    
    //TLE
    void findIter(
        string src, int& noUsed, vector<int>& used,
        vector<pair<string, string>>& tickets,
        vector<string> & curr,
        vector<string> & res) {
        
        if(noUsed >= tickets.size()) {
            
            res = curr;
        }
        else {
            
            priority_queue<pair<string, int>> q_;
            
            for(int ticket = 0; ticket < tickets.size(); ticket++) {
                
                if(tickets[ticket].first == src && !used[ticket]) {
                    
                    q_.push(
                        make_pair<>(tickets[ticket].second, ticket));
                }
            }
            
            while(!q_.empty() && noUsed < tickets.size()) {
                
                auto it = q_.top();
                
                q_.pop();
                
                used[it.second] = 1;
                ++noUsed;
                
                curr.push_back(it.first);
                
                findIter(it.first, noUsed, used, tickets, curr, res);
                
                curr.pop_back();
                --noUsed;
                used[it.second] = 0;
            }
            
        }
    }
};