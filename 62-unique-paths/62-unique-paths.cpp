// Recursion se kiya , TLE aa gaya, TC-> exponential
// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n)
//     {
//         // Base Case
//         if(i>=m || j>=n)
//             return 0;
//         if(i==(m-1) && j==(n-1))
//             return 1;
//         else
//             return countPaths(i+1, j, m, n) + countPaths(i, j+1, m, n);
//     }
//     int uniquePaths(int m, int n) {
//         int ans = countPaths(0,0,m,n);
//         return ans;
//     }
// };

// DP se kiya, TLE aa gaya, TC -> 
// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n, vector<vector<int>>dp)
//     {
//         // Base Case
//         if(i>=m || j>=n)
//             return 0;
//         if(i==(m-1) && j==(n-1))
//             return 1;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
              
//         else
//             return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         vector<vector<int>> v(rows, vector<int> (cols, 1));  /*creates 2d vector “v[rows][cols]” and initializes all elements to “1” (default value is 0)*/
        
//         int ans = countPaths(0,0,m,n,dp);
//         return ans;
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};