class Solution {
private:
    int f(vector<int>& nums,int ftidx,int i,vector<int>& dp){
        if(i<ftidx) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(nums,ftidx,i-2,dp);
        int notpick = f(nums,ftidx,i-1,dp);
        return dp[i] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int pickfirst = f(nums,0,n-2,dp1);
        int notpickfirst = f(nums,1,n-1,dp2);
        return max(pickfirst,notpickfirst);
    }
};