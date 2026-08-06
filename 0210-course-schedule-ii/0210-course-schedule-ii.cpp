class Solution {
private:
    bool dfs(vector<vector<int>>& adj,vector<int>& pathvis,vector<int>& visited,int node,stack<int>& stk){
        visited[node] = 1;
        pathvis[node] = 1;
        for(auto& neigh:adj[node]){
            if(!visited[neigh]){
                if (dfs(adj,pathvis,visited,neigh,stk)) return true;
            }else if(pathvis[neigh]){
                return true;
            }
        }
        pathvis[node] = 0;
        stk.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& edge:prerequisites){
            int u = edge[0],v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        vector<int> pathvis(n,0);
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,pathvis,visited,i,stk)) return {};
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;

    }
};