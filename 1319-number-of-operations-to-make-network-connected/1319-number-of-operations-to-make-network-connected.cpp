class Solution {
private:
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int node){
        visited[node] = 1;
        for(auto& neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,visited,neigh);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        int noofedges = connections.size();
        if(noofedges < n-1) return -1;
        for(auto& edge:connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                cnt++;
            }
        }
        return (cnt-1);
    }
};