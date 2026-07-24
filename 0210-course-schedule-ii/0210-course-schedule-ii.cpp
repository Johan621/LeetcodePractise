class Solution {
private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis,stack<int>& st){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,pathvis,st)) return true;;
            }else if(vis[neigh] == 1 && pathvis[neigh] == 1){
                return true;
            }
        }
        pathvis[node] = 0;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,st)) return {};
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};