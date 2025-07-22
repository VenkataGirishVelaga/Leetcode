class Solution {
public:    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);

        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--){
            int mini = INT_MAX;
            for(int j = i; j < n; j++){
                if(isPal[i][j]){
                    int cost = 1 + dp[j+ 1];
                    mini = min(mini, cost);
                } 
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};