class Solution {
public:
    bool ispal(int i, int j, const string& s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0); 

        for(int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            for(int j = i; j < n; j++) {
                if(ispal(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};
