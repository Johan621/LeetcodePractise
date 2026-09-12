class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> path(5, vector<vector<int>>(n + 1));

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {
                int j = lower_bound(
                    ends.begin(),
                    ends.begin() + i - 1,
                    a[i - 1][0]
                ) - ends.begin();

                long long takeScore = dp[k - 1][j] + a[i - 1][2];
                long long skipScore = dp[k][i - 1];

                vector<int> takePath = path[k - 1][j];
                takePath.push_back(a[i - 1][3]);

                vector<int> skipPath = path[k][i - 1];

                sort(takePath.begin(), takePath.end());
                sort(skipPath.begin(), skipPath.end());

                if (takeScore > skipScore) {
                    dp[k][i] = takeScore;
                    path[k][i] = takePath;
                }
                else if (takeScore < skipScore) {
                    dp[k][i] = skipScore;
                    path[k][i] = skipPath;
                }
                else {
                    dp[k][i] = takeScore;

                    if (takePath < skipPath)
                        path[k][i] = takePath;
                    else
                        path[k][i] = skipPath;
                }
            }
        }

        return path[4][n];
    }
};