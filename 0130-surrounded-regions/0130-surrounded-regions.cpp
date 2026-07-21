class Solution {
private:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(board[i][j] != 'O') return;
        board[i][j] = 'J';
        dfs(board,i,j-1);
        dfs(board,i,j+1);
        dfs(board,i+1,j);
        dfs(board,i-1,j);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }
            if(board[m-1][j] == 'O'){
                dfs(board,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1);
            }
        }

        for(auto& row:board){
            for(auto& ele:row){
                if(ele == 'O') ele = 'X';
                if(ele == 'J') ele = 'O';
            }
        }
    }
};