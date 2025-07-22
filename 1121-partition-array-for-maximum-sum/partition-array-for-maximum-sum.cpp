class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        for(int i = n - 1; i >= 0; i--){
            int len = 0;
            int maxi = INT_MIN;
            int maxians = INT_MIN;
            for(int j = i; j < min(n, i + k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxians = max(maxians, sum);
            }
            dp[i] = maxians;
        }
        return dp[0];
    }
};