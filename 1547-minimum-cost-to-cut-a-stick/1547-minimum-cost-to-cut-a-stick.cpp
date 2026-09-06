class Solution {
public:

    int dp[110][110];

    int rec(int l, int r, vector<int>& cuts) {

        // No cut possible between l and r
        if (l + 1 == r) {
            return 0;
        }

        if( dp[l][r] != -1) return dp[l][r];

        int ans = INT_MAX;

        // Try every possible first cut
        for (int p = l + 1; p < r; p++) {

            int cost = cuts[r] - cuts[l]
                     + rec(l, p, cuts)
                     + rec(p, r, cuts);

            ans = min(ans, cost);
        }

        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        memset( dp , -1 , sizeof( dp ));

        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort all cut positions
        sort(cuts.begin(), cuts.end());

        return rec(0, cuts.size() - 1, cuts);
    }
};