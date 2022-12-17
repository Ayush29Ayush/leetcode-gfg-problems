//! STRIVER 39, STOCKS 2 ka continuation
class Solution {
public:
        //! MEMOIZATION
    int func(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
    {
        // base case
        if(ind>=n)
            return 0;

        if(dp[ind][buy]!=-1)
            return dp[ind][buy];

        // take means voh din chose kiya for buying or selling and nottake ka vica versa
        if(buy==1)
        {
            // means buying is allowed
                // int take = -price[ind] + func(ind+1, 0, price, n, dp);
                // int nottake = 0 + func(ind+1, 1, price, n, dp);
                // return dp[ind][buy] = max(take, nottake);
            return dp[ind][buy] = max(-price[ind] + func(ind+1, 0, price, n, dp), 0 + func(ind+1, 1, price, n, dp));
        }
        if(buy==0)
        {
            // means selling is allowed
                // int take = +price[ind] + func(ind+2, 1, price, n, dp);
                // int nottake = 0 + func(ind+1, 0, price, n, dp);
                // return dp[ind][buy] = max(take, nottake);
            // ind+2 after selling so that 1 day ka cooldown mil jaye
            return dp[ind][buy] = max(+price[ind] + func(ind+2, 1, price, n, dp), 0 + func(ind+1, 0, price, n, dp));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return func(0,1,prices,n,dp);
    }
};