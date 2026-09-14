class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int num:nums){
            freq[num]++;
        }
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] == nums [j] && nums[j] == nums[k] && freq[nums[i]] == 3 && j-i == k-j){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};