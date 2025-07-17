class Solution {
public:
    void dfs(int node, int cpmnt, vector<vector<int>>& adj, vector<int>& visited, vector<int>& component) {
        visited[node] = 1;
        component[node] = cpmnt;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, cpmnt, adj, visited, component);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {  
        vector<vector<int>> adj(c + 1);
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(c + 1, false);
        vector<int> component(c + 1, -1);
        int cpmnt = 0;
        for(int i = 1; i <= c; i++){
            if(!visited[i]){
                dfs(i, cpmnt++, adj, visited, component);
            }
        }
        vector<bool> active(c + 1, true);
        unordered_map<int, set<int>> ans;
        for(int i = 1; i <= c; i++){
            ans[component[i]].insert(i);
        }
        vector<int> res;
        for(auto it : queries){
            int type = it[0];
            int node = it[1];
            int cmt = component[node];
            
            if(type == 1){
                if(active[node]){
                    res.push_back(node);
                }else{
                    if(ans[cmt].empty()) res.push_back(-1);
                    else{
                        res.push_back(*ans[cmt].begin());
                    }
                }
            } else if(type == 2) {
                if(active[node]){
                    active[node] = false;
                    ans[cmt].erase(node);
                }
            }
        }
        return res;
    }
};