class Solution {
public:
    int ans(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int maxi = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || height[st.top()] >= height[i])){
                int ele = height[st.top()];
                st.pop();
                int width = 0;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxi = max(maxi, ele * width);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<int> height(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int res = ans(height);
            maxi = max(maxi, res);
        }
        
        return maxi;
    }
};