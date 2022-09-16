// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/2581635/LeetCode-The-Hard-Way-Explained-Line-By-Line
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = (int) nums.size(), m = (int) multipliers.size();
        vector<int> dp(m + 1);
        // let's think backwards
        for (int i = 0; i < m; i++) {
            // at round m, we  pick the m-th multiplier
            // at round m - 1, we pick the (m - 1)-th multiplier
            // at round m - 2, we pick the (m - 2)-th multiplier
            // and so on ... 
            int mult = multipliers[m - 1 - i];
            // how many elements we need to process? 
            // at round m, there are m elements
            // at round m - 1, there are m - 1 elements
            // at round m - 2, there are m - 2 elements
            // and so on ...
            for (int j = 0; j < m - i; j++) {
                // so we take the max of
                dp[j] = max(
                    // the start
                    mult * nums[j] + dp[j + 1], 
                    // the end
                    mult * nums[j + (n - (m - i))] + dp[j]
                );
            }
        }
        return dp[0];
    }
};