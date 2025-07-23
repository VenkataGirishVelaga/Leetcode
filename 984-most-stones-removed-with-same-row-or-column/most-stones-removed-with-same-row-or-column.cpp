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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0, maxcol = 0;
        for(auto& it : stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        disjoint ds(maxrow + maxcol + 2);
        unordered_set<int> s;
        for(auto& it : stones){
            int rownode = it[0];
            int colnode = it[1] + maxrow + 1;
            ds.unionsz(rownode, colnode);
            s.insert(rownode);
            s.insert(colnode);
        }
        int cnt = 0;
        for(int it : s){
            if(ds.findup(it) == it) cnt++;
        }
        return n - cnt;
    }
};