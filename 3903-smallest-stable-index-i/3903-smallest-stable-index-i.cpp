class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n),suffmin(n);
        premax[0] = nums[0];
        suffmin[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            premax[i] = max(premax[i-1],nums[i]);
            suffmin[n-i-1] = min(suffmin[n-i],nums[n-i-1]);
        }
        for(int i=0;i<n;i++){
            if((premax[i]-suffmin[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};