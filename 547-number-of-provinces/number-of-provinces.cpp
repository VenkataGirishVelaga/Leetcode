class disjoint{
    public:
        vector<int> parent, size;
        disjoint(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findupr(int node){
            if(node == parent[node]) return node;

            return parent[node] = findupr(parent[node]);
        }

        void disiz(int u, int v){
            int up_u = findupr(u);
            int up_v = findupr(v);

            if (up_u == up_v) return;
            if(size[up_v] < size[up_u]){
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }else{
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            } 
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjoint ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    ds.disiz(i, j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) cnt++;
        }

        return cnt;
    }
};