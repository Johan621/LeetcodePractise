class Solution {
private:
    int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == n) return 0; 
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int left = f(i+1,j,n,triangle,dp);
        int right = f(i+1,j+1,n,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return f(0,0,n,triangle,dp);
    }
};