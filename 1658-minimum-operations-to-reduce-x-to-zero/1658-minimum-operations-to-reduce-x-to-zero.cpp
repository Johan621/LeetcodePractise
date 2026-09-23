class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        // We need to keep a subarray whose sum is total - x
        long long target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a valid subarray
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};