class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(auto neigh:adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        if(topo.size() == V) return topo;
        return {};

    }
};