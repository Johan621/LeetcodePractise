class Solution {
private:
    int f(vector<int>& nums,int i,vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(nums,i-2,dp);
        int notpick = f(nums,i-1,dp);
        return dp[i] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,nums.size()-1,dp);
    }
};