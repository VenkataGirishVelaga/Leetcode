class disjoint{
public:
    vector<int> parent, size;
    disjoint(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findup(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findup(parent[node]);
    }

    void unionsz(int u, int v){
        int upu = findup(u);
        int upv = findup(v);

        if(upu == upv) return;

        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        }else{
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
class Solution {
private:
    bool isvalid(int nrow, int ncol, int n){
        return nrow >= 0 && ncol < n && nrow < n && ncol >= 0;
    }
public:
    vector<int> delr = {-1, 0, 1, 0};
    vector<int> delc = {0, -1, 0, 1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n * n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int nrow = i + delr[k];
                    int ncol = j + delc[k];
                    if(isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                        int nodeno = i * n + j;
                        int adjnodeno = nrow * n + ncol;
                        ds.unionsz(nodeno, adjnodeno);
                    }
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                set<int> comp;
                for(int k = 0; k < 4; k++){
                    int nrow = i + delr[k];
                    int ncol = j + delc[k];
                    if(isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                        comp.insert(ds.findup(nrow * n + ncol));
                    }
                }
                int sz = 0;
                for(auto& it : comp){
                    sz += ds.size[it];
                }
                mx = max(mx, sz + 1);
            } 
        }

        for(int i = 0; i < n * n; i++){
            mx = max(mx, ds.size[ds.findup(i)]);
        }
        return mx;

    }
};