class Solution {
private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvis,vector<int>& check){
        visited[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                if(dfs(neigh,adj,visited,pathvis,check)) return true;
            }
            else if(pathvis[neigh] == 1){
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited,pathvis,check);
            }
        }
        vector<int> safenodes;
        for(int i=0;i<V;i++){
            if(check[i]) safenodes.push_back(i);
        }
        return safenodes;
    }
};