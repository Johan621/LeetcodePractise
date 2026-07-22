class Solution {
private:
    bool dfs(vector<vector<int>>& adj,int node,int des,vector<int>& visited){
        if(node == des) return true;
        visited[node] = 1;
        for(int neigh: adj[node]){
            if(!visited[neigh]){
                if(dfs(adj,neigh,des,visited)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        return dfs(adj,source,destination,visited);
    }
};