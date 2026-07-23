class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>> dist(m,vector<int>(n,0));
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[row][col] = step;
            for(int i=0;i<4;i++){
                int nr = row+drow[i];
                int nc = col+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    q.push({{nr,nc},step+1});
                }
            }
        }
        return dist;
        
    }
};