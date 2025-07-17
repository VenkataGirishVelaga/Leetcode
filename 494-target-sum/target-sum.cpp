class Solution {
public:
    int findways(int n, vector<int>& nums, int target) {
        vector<int> prev(target + 1);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            vector<int> curr(target + 1);
            for(int t = 0; t <= target; t++){
                int notake = prev[t];
                int take = 0;
                if(nums[i] <= t) take = prev[t - nums[i]];
                curr[t] = take + notake;
            }
            prev = curr;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum - target < 0 || (sum - target) % 2 != 0){
            return 0;
        }

        return findways(n, nums,(sum - target)/2);
    }
    
};