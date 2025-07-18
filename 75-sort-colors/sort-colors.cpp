class Solution {
public:
    void sortColors(vector<int>& nums) {
        int onec = 0;
        int  zeroc = 0;
        int  twos = 0;
        for(int& ele : nums){
            if(ele == 0) zeroc++;
            else if(ele == 1) onec++;
            else twos++;
        }
        
        for(int i = 0; i < zeroc; i++){
            nums[i] = 0;
        }
        for(int i = zeroc; i < zeroc + onec; i++){
            nums[i] = 1;
        }
        for(int i = zeroc + onec; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};