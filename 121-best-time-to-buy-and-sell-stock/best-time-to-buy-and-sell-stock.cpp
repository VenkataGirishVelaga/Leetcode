class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int small = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > small){
                maxi = max(maxi, prices[i] - small);
            }else{
                small = prices[i];
            }
        }
        return maxi;
    }
};