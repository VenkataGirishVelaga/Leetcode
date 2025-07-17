class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) prev[i] = 1;
            
        }
        
        for(int i = 1; i < n; i++){
            vector<int> curr(amount + 1);
            for(int t = 0; t <= amount; t++){
                long long notake = prev[t];
                long long take = 0;
                if(coins[i] <= t) take = curr[t - coins[i]];
                curr[t] = take + notake;
            }
            prev = curr;
        }
        int ans =  prev[amount];
       
        return ans;
    }
};