class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int afterbuy = 0, afternotbuy = 0;
        for(int i = n - 1; i >= 0; i--){
            int currbuy = max(-prices[i] + afternotbuy, afterbuy);
            int currnotbuy = max(prices[i] - fee + afterbuy, afternotbuy);

            afterbuy = currbuy;
            afternotbuy = currnotbuy;
        }
        return afterbuy;
    }
};