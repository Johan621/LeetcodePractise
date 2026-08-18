class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]+=1;
        }
        if(k == 1){
            int ans = -1;
            for(auto& pair:mp){
                if(pair.second == 1) ans = max(ans,pair.first);
            }
            return ans;
        }
        if(k == n) return *max_element(nums.begin(),nums.end());

        int ans = -1;
        if(mp[nums[0]] == 1) ans = max(ans,nums[0]);
        if(mp[nums[n-1]] == 1) ans = max(ans,nums[n-1]);
        return ans;
    }
};