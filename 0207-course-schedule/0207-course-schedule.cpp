class Solution {
private:
    bool dfs(vector<vector<int>>& adj,vector<int>& visited,int node,vector<int>& pathvis){
        visited[node] = 1;
        pathvis[node] = 1;
        for(auto& neigh:adj[node]){
            if(!visited[neigh]){
                if(dfs(adj,visited,neigh,pathvis)) return true;
            }else if(pathvis[neigh] == 1) return true;
        }
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& edge:prerequisites){
            int u = edge[0],v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> visited(n,0);
        vector<int> pathvis(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if (dfs(adj,visited,i,pathvis)) return false;
            }
        }
        return true;
    }
};