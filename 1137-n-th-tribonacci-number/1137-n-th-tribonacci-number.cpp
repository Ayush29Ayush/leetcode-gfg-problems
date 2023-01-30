// TC: O(N)
// SC: O(N)
class Solution {
public:
	// since first three numbers are given, 
	// let dp[i] be the value of T_n
	// we can build the dp[i] based on dp[i - 1] + dp[i - 2] + dp[i - 3]
    int tribonacci(int n) {
	    // first three numbers are known
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
		// dp[i]: the value of T_n
        vector<int> dp(n + 1);
		// base case
        dp[0] = 0;
        dp[1] = dp[2] = 1;
		// dp[i] is the sum of the previous three values
        for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};