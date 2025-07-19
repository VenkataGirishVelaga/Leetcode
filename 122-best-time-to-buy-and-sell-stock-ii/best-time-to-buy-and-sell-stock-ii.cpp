class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2), curr(2);
        for(int i = n - 1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                
                if(buy){
                    curr[1] = max(-prices[i] + after[0], after[1]);
                }else{
                    curr[0] = max(prices[i] + after[1], after[0]);
                }
            }
            after = curr;
        }
        return after[1];
    }
};