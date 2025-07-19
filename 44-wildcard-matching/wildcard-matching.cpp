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
        vector<bool> prev(n + 1,false);
        prev[0] = true;

        // for(int i = 1; i <= m; i++){
        //     dp[i][0] = isvalid(p, i);
        // }

        for(int i = 1; i <= m; i++){
            vector<bool> curr(n + 1, false);
            curr[0] = isvalid(p, i);
            for(int j = 1; j <= n; j++){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    curr[j] = prev[j - 1];
                }else if(p[i - 1] == '*'){
                    curr[j] = prev[j] || curr[j - 1];
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};