class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);

        long long maxsum = -1;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                int curr = i;

                while(curr != -1 && vis[curr] == 0){
                    vis[curr] = 1;
                    curr = edges[curr];
                }
                if(curr != -1 && vis[curr] == 1){
                    long long cyclesum = 0;
                    int startNode = curr;
                    int temp = curr;
                    do{
                        cyclesum += 1;
                        temp = edges[temp];

                    }while(temp != startNode);
                    maxsum = max(maxsum,cyclesum);
                }
                curr = i;
                while(curr != -1 && vis[curr] == 1){
                    vis[curr] = 2;
                    curr = edges[curr];
                }
            }
        }
        return maxsum;
    }
};