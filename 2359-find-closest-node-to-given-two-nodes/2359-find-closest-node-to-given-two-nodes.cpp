class Solution {
private:
    void getdist(int node,vector<int>& edges,vector<int>& dist){
        int d = 0;
        while(node != -1 && dist[node] == -1){
            dist[node] = d;
            d++;
            node = edges[node];
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        getdist(node1,edges,dist1);
        getdist(node2,edges,dist2);

        int mindist = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int maxdist = max(dist1[i],dist2[i]);

                if(maxdist < mindist){
                    mindist = maxdist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};