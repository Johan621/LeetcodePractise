class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = whether s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 2) {
                        pal[i][j] = true;
                    } else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using s[0...i]
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            // Don't take a palindrome ending at i
            if (i > 0) {
                dp[i] = dp[i - 1];
            }

            // Try every palindrome ending at i
            for (int j = 0; j <= i; j++) {

                int len = i - j + 1;

                if (len >= k && pal[j][i]) {

                    int previous = (j > 0) ? dp[j - 1] : 0;

                    dp[i] = max(dp[i], previous + 1);
                }
            }
        }

        return dp[n - 1];
    }
};