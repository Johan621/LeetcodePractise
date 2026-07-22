class Solution {
private:
    void dfs(vector<int> adj[],vector<int>& visited,int node){
        visited[node] = 1;
        
        for(auto& neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,visited,neigh);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,visited,i);
            }
        }
        return cnt;
    }
};