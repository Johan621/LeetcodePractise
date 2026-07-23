class Solution {
    private:
        bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvis){
            visited[node] = 1;
            pathvis[node] = 1;
            for(auto neigh:adj[node]){
                if(!visited[neigh]){
                    if(dfs(neigh,adj,visited,pathvis)) return true;
                }else if(pathvis[neigh] == 1){
                    return true;
                }
            }
            pathvis[node] = 0;
            return false;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> pathvis(numCourses,0);

        vector<vector<int>> adj(numCourses);
        for(auto& edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathvis) == true) return false;
            }
        }
        return true;
    }
};