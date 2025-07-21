class Solution {
public:
    bool compare(string& a, string& b){
        if(a.size() != b.size() + 1) return false;
        int p1 = 0, p2 = 0;
        while(p1 < a.size()){
            if(p2 < b.size() && a[p1] == b[p2]){
                p1++;
                p2++;
            }else{
                p1++;
            }
        }
        if(p1 == a.size() && p2 == b.size()) return true;
        return false;
    }
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};