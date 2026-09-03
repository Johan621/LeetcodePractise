class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int s = *min_element(nums1.begin(),nums1.end());
        bool even = true;
        for(int x:nums1){
            if(x%2 != 0){
                even = false;
                break;
            }
        }
        if(even) return true;
        return s%2==1;
    }
};