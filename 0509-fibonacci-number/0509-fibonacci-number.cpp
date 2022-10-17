//! using RECURSION
// class Solution {
// public:
//     int fib(int n) {
//         //Base Case
//         if(n==0)
//             return 0;
//         if(n==1)
//             return 1;
        
//         // Recurrence Relation
//         int ans = fib(n-1)+fib(n-2);
        
//         return ans;
//     }
// };

//! using DP - using TABULATION(Bottom-Up)
// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n+2,-1);
        
//         dp[0] = 0;
//         dp[1] = 1;
        
//         for(int i = 2; i<=n; i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
        
//         return dp[n];
//     }
// };

//! using DP - using MEMOIZATION
class Solution {
public:
    int func(int n, vector<int> &dp)
    {
        if(n<=1) 
            return n;
    
        if(dp[n]!= -1) 
            return dp[n];

        dp[n]= func(n-1,dp) + func(n-2,dp);

        return dp[n]; 
    }
    
    int fib(int n) {
        vector<int> dp(n+1, -1);
        int ans = func(n,dp);
        return ans;
    }
};