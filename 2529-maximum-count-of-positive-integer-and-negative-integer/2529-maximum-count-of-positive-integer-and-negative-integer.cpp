class Solution {
public:
    int nonnegative(vector<int>& nums){
        int n = nums.size();
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<0){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }

    int firstpos(vector<int>& nums){
        int n = nums.size();
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>0){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    int maximumCount(vector<int>& nums) {
        int neg = nonnegative(nums);
        int pos = nums.size() - firstpos(nums);
        return max(pos,neg);
    }
};