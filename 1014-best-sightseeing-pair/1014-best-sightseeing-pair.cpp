//dp array me first row matlab ki uss tak max first number.
//second row matlab ki second number pair ka maximum vaha tak 
//relation is values[i]+i + values[j]-j ye dono values ko maximum karo.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(2,vector<int> (n,0));
        int ans = INT_MIN;

        dp[0][0] = values[0];
        dp[1][0] = INT_MIN;

        for(int i=1;i<n;i++){
            dp[0][i] = max(dp[0][i-1],values[i]+i);
            dp[1][i] = values[i] - i;
            ans = max(ans,dp[0][i-1]+dp[1][i]);
        }
        return ans;
    }
};