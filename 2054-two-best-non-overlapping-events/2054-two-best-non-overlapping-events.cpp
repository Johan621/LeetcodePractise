class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]);
            int target = events[i][1] + 1;
            int left = i + 1;
            int right = n - 1;
            int pos = n;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (events[mid][0] >= target) {
                    pos = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (pos < n) {
                ans = max(ans, events[i][2] + suffixMax[pos]);
            }
        }
        return ans;
    }
};