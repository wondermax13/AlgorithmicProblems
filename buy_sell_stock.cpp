class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int size   = prices.size();
        
        if(size > 1) {
            
            int cp = prices[0];
            
            for(int index = 1; index < size; index++) {
                
                if(prices[index] > prices[index -1]) {
                    
                    profit += (prices[index] - prices[index - 1]);
                    
                    //cp = prices[index];
                }
            }
        }
        
        return profit;
    }
};