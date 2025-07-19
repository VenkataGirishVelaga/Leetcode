class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f1(2), f2(2), curr(2);
        for(int i = n - 1; i >= 0; i--){
            curr[1] = max(-prices[i] + f1[0], f1[1]);
            curr[0] = max(prices[i] + f2[1], f1[0]);
            f2 = f1;
            f1 = curr;
        }
        return curr[1];
    }
};