class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>& dp){
        if(i < 0) return 0;
        if(i == 1 || i == 0) return cost[i];
        if(dp[i] != -1) return dp[i];
        int left = f(i-1,cost,dp);
        int right = f(i-2,cost,dp);

        return dp[i] = cost[i] + min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};