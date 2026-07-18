class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=nums[0];i>=1;i--){
            if(nums[0]%i == 0 && nums[nums.size()-1]%i == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};