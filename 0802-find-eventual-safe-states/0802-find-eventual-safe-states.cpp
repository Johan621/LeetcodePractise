class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // kahn's Topo-sort algorithm
        vector<vector<int>> adjrev(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto neigh: graph[i]){
                adjrev[neigh].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safenodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto neigh:adjrev[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};