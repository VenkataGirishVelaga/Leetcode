class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
        dp[n][0] = true;

        for(int i = n - 1; i >= 0; i--){
            for(int open = 0; open <= n; open++){
                if(s[i] == '('){
                    if(open + 1 <= n){
                        dp[i][open] = dp[i + 1][open + 1];
                    }
                }else if(s[i] == ')'){
                    if(open - 1 >= 0){
                        dp[i][open] = dp[i + 1][open - 1];
                    }
                }else{
                    bool empty = dp[i + 1][open];
                    bool left = (open + 1 <= n) ? dp[i + 1][open + 1] : false;
                    bool right = (open - 1>= 0) ? dp[i + 1][open - 1] : false;

                    dp[i][open] = empty || left || right;
                }
            }
        }
        return dp[0][0];
    }
};