class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> prev(m + 1);
        prev[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = m; j > 0; j--){
                if(s[i - 1] == t[j - 1]){
                    prev[j] = prev[j - 1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};