class Solution {
private:
    class Disjointset{
    public:
        vector<int> parent;
        vector<int> size;
        Disjointset(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int findUpar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUpar(parent[node]);
        }
        void unionBysize(int u,int v){
            int pu = findUpar(u);
            int pv = findUpar(v);
            if(pu == pv){
                return;
            }
            if(size[pu]<size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noofedges = connections.size();
        if(noofedges < n-1) return -1;
        
        Disjointset dsu(n);

        for(auto& edge:connections){
            int u = edge[0];
            int v = edge[1];
            dsu.unionBysize(u,v);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dsu.findUpar(i) == i){
                cnt++;
            }
        }
        return cnt-1;
    }
};