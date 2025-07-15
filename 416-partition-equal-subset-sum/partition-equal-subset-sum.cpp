class Solution {
public:
    bool res(int n, int k, vector<int>& nums){
        vector<bool> prev(k + 1);
        prev[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;
        for(int i = 1; i < n; i++){
            vector<bool> curr(k + 1);
            curr[0] = true;
            for(int target = 1; target <= k; target++){
                bool nottake = prev[target];
                bool take = false;
                if(nums[i] <= target) take = prev[target - nums[i]];
                curr[target] = take + nottake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i < n; i++) totalsum += nums[i];
        if(totalsum % 2 != 0) return false;
        int target = totalsum/2;

        return res(n, target, nums);
    }
};