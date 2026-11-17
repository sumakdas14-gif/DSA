class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Calculate minimum changes for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int rem = 0; rem < d; rem++) {
                        int cnt = len / d;

                        for (int x = 0; x < cnt / 2; x++) {
                            int a = l + rem + x * d;
                            int b = l + rem + (cnt - 1 - x) * d;

                            if (s[a] != s[b])
                                changes++;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, -1));

        function<int(int, int)> solve =
        [&](int pos, int parts) -> int {

            if (parts == 0)
                return pos == n ? 0 : INF;

            if (n - pos < 2 * parts)
                return INF;

            int &ans = dp[pos][parts];

            if (ans != -1)
                return ans;

            ans = INF;

            int maxEnd = n - 2 * (parts - 1) - 1;

            for (int end = pos + 1; end <= maxEnd; end++) {
                ans = min(ans,
                          cost[pos][end] +
                          solve(end + 1, parts - 1));
            }

            return ans;
        };

        return solve(0, k);
    }
};