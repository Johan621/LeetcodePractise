class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& visited,int drow[],int dcol[],vector<vector<int>>& grid){
        visited[row][col] = 1;
        for(int i=0;i<4;i++){
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && visited[nr][nc] == 0 && grid[nr][nc] == 1){
                dfs(nr,nc,visited,drow,dcol,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int j=0;j<n;j++){
            if(!visited[0][j] && grid[0][j] == 1){
                dfs(0,j,visited,drow,dcol,grid);
            }
            if(!visited[m-1][j] && grid[m-1][j] == 1){
                dfs(m-1,j,visited,drow,dcol,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i,0,visited,drow,dcol,grid);
            }
            if(!visited[i][n-1] && grid[i][n-1] == 1){
                dfs(i,n-1,visited,drow,dcol,grid);
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};