class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2));
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue;
                long long maxi = LLONG_MIN;
                for(int k = i; k <= j; k++){
                    long long cost = 1LL * nums[i - 1] * nums[j + 1] * nums[k] + dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};