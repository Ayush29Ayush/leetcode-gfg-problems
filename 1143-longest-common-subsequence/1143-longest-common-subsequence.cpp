//DP on strings use 2d DP and match/not match concept .
// MEMOIZATION was giving TLE, refer notion notes for that
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 //matching
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 //not matching case then check in pevious values.
//                 else{
//                     dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
// };

//! MEMOIZATION striver
class Solution {
        public:
            int pre(int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
                if(n < 0 or m < 0) return 0;
                if(dp[n][m]!=-1) return dp[n][m];
                if(s1[n] == s2[m]) return dp[n][m] = pre(n-1,m-1,s1,s2,dp) + 1;
                else return dp[n][m] = max(pre(n-1,m,s1,s2,dp),pre(n,m-1,s1,s2,dp));
            }
            int longestCommonSubsequence(string text1, string text2) {
                int n = text1.size();
                int m = text2.size();
                vector<vector<int>> dp(n,vector<int> (m,-1));
                pre(n-1,m-1,text1,text2,dp);
                return dp[n-1][m-1];
            }
        };

//! MEMOIZATION with RIGHT SHIFT striver
// class Solution {
//         public:
//             int pre(int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
//                 if(n == 0 or m == 0) return 0;
//                 if(dp[n][m]!=-1) return dp[n][m];
//                 if(s1[n-1] == s2[m-1]) return dp[n][m] = pre(n-1,m-1,s1,s2,dp) + 1;
//                 else return dp[n][m] = max(pre(n-1,m,s1,s2,dp),pre(n,m-1,s1,s2,dp));
//             }
//             int longestCommonSubsequence(string text1, string text2) {
//                 int n = text1.size();
//                 int m = text2.size();
//                 vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
//                 cout<<pre(n,m,text1,text2,dp)<<endl;
//                 return dp[n][m];
//             }
//         };