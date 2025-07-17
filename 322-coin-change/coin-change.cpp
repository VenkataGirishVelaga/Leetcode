class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }
        for(int i = 1; i < n; i++){
            vector<int> curr(amount + 1);
            for(int t = 0; t <= amount; t++){
                int NoTake = prev[t];
                int Take = INT_MAX;
                if(coins[i] <= t) Take = 1 + curr[t - coins[i]];
                curr[t] = min(Take, NoTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};