class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int x:nums)
            total += x;
        int leftsum = 0;
        for(int i=0;i<n;i++){
            int rightsum = total - leftsum - nums[i];
            if(leftsum == rightsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};