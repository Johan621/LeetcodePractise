class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& edge:times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            if(d>dist[node])
                continue;
            for(auto &[neigh,weight]:adj[node]){
                if(d+weight<dist[neigh]){
                    dist[neigh] = d+weight;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<n+1;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};