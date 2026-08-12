class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]<=k){
                maxi = max(maxi,j-i+1);
            }else{
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};