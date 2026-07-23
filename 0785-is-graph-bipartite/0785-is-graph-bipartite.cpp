class Solution {
private:
    bool bfs(int start,vector<vector<int>>& adj,vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neigh:adj[node]){
                if(color[neigh] == -1){
                    color[neigh] = !color[node];
                    q.push(neigh);
                }else if(color[neigh] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(!bfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};