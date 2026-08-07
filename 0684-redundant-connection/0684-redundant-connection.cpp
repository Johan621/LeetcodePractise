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
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionBysize(int u,int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjointset dsu(n+1);
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(dsu.findUpar(u) == dsu.findUpar(v)){
                return edge;
            }
            dsu.unionBysize(u,v);
        }
        return {};
    }
};