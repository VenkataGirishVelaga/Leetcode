class Solution {
public:
    bool isvalid(string& p, int i){
        for(int a = 0; a < i; a++){
            if(p[a] != '*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= m; i++){
            dp[i][0] = isvalid(p, i);
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};