class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        int zerocnt = 0;
        for(int num:nums){
            xor1 ^= num;
            if(num == 0) zerocnt++;
        }
        if(xor1 != 0){
            return n;
        }
        if(zerocnt == n) return 0;
        return n-1;
    }
};