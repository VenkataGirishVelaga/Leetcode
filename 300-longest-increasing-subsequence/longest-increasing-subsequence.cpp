class Solution {
public:
    int func(int id, int prev, vector<vector<int>>& dp, vector<int>& nums){
        if(id == nums.size()) return 0;
        if(dp[id][prev + 1] != -1) return dp[id][prev + 1];
        int len = func(id + 1, prev, dp, nums);
        if(prev == -1 || nums[id] > nums[prev]){
            len = max(len, 1 + func(id + 1, id, dp, nums));
        }
         return dp[id][prev + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(0, -1, dp, nums);
    }
};