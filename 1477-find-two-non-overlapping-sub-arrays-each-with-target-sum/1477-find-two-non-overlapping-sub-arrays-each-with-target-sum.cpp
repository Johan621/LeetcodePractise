class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const int INF = 1e9;

        // best[i] = shortest target-sum subarray
        // completely before index i
        vector<int> best(n + 1, INF);

        int answer = INF;

        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {

            // Add current element
            sum += arr[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // If current window has sum = target
            if (sum == target) {

                int currentLength = right - left + 1;

                // Check if there is a previous
                // non-overlapping target subarray
                if (best[left] != INF) {
                    answer = min(
                        answer,
                        best[left] + currentLength
                    );
                }
            }

            // Carry forward the best previous subarray
            best[right + 1] = best[right];

            // If current window is valid,
            // update best
            if (sum == target) {
                int currentLength = right - left + 1;

                best[right + 1] =
                    min(best[right + 1], currentLength);
            }
        }

        return answer == INF ? -1 : answer;
    }
};