class NumArray {
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        if(nums.empty()) return;
        presum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            presum.push_back(presum.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return presum[right];
        return presum[right]-presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */