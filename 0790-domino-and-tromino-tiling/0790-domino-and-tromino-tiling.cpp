// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/1620975/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-Optimization-from-Brute-Force-to-DP
// Tiling from Start-to-End
class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1001][2]{};
    int numTilings(int n) {
        return solve(0, n, false);
    }
    long solve(int i, int n, bool previousGap) {
        if(i > n) return 0;
        if(i == n) return !previousGap;
        if(dp[i][previousGap]) return dp[i][previousGap];
        if(previousGap)
            return dp[i][previousGap] = (solve(i+1, n, false) + solve(i+1, n, true)) % MOD;
        return dp[i][previousGap] = (solve(i+1, n, false) + solve(i+2, n, false) + 2*solve(i+2, n, true)) % MOD;
    }
};