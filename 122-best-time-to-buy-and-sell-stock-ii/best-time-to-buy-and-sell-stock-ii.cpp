class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadbuy = 0, aheadNotbuy = 0;
        for(int i = n - 1; i >= 0; i--){
           int currbuy = max(-prices[i] + aheadNotbuy, aheadbuy);
           int currNotbuy = max(prices[i] + aheadbuy, aheadNotbuy);

            aheadbuy = currbuy;
            aheadNotbuy = currNotbuy;

        }
        return aheadbuy;
    }
};