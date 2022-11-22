//! DP Lec112 Babbar
class Solution {
public:
    int fmemo(int n, vector<int> &dp)
    {
        // base case
        // 0 banane ke 0 tarike
        if(n==0)
            return 0;
        if(n<0)
            return INT_MAX-1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;
        for(int i = 1; i*i<=n; i++)
        {
            ans = min(ans, 1+fmemo(n-i*i, dp)); // +1 because call ke time uss element ko bhi utilize kiya hai like if n=5 toh n=4 ko call jayega/
            // so n=4 jab return karega, toh uska return value + voh n=4 wala element bhi use hoga. Isiliye +1 hai since n=4 bhi consider hua 
        }
        
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return fmemo(n,dp);
    }
};