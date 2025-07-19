class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2 * k + 1), curr(2 * k + 1);

        for(int i = n - 1;i >= 0; i--){
            for(int cap = 2 * k - 1; cap >= 0; cap--){
                if(cap % 2 == 0){
                    curr[cap] = max(-prices[i] + after[cap + 1], after[cap]);
                }else{
                    curr[cap] = max(prices[i] + after[cap + 1], after[cap]);
                }
            }
            after = curr;
        }
        return after[0];
    }
};