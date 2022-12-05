//DP on strings use 2d DP and match/not match concept .
// MEMOIZATION was giving TLE, refer notion notes for that
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                //matching
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //not matching case then check in pevious values.
                else{
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};