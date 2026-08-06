class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,-1,0,1};
        int tm = 0;
        while(!q.empty()){
            int size = q.size();
            auto [r,c] = q.front().first;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            while(size--){
                for(int i=0;i<4;i++){
                    int nrow = r+drow[i];
                    int ncol = c+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({{nrow,ncol},t+1});
                    }
                }
            }
        }
        return (fresh==0)?tm:-1;
    }
};