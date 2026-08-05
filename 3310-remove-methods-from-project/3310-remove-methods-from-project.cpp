class Solution {
private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node] = 1;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto& edge:invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0);
        dfs(k,adj,vis);

        for(auto& edge:invocations){
            int u = edge[0];
            int v = edge[1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};