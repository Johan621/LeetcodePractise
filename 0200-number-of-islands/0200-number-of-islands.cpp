class Solution {

public:
    bool dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return false;
        if(grid[i][j] == '0' || visited[i][j]){
            return false;
        }
        visited[i][j] = true;
        dfs(grid,i,j-1,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i+1,j,visited);
        return true;
    } 
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(grid,i,j,visited)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};