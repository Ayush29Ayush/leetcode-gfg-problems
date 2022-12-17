//! STRIVER 40
class Solution {
public:
    //! MEMOIZATION
    int funcmemo(int ind, int buy, int fees, vector<int>& prices, int n, vector<vector<int>> &dp)
    {
        // base case
        if(ind==n)
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        if(buy==1) // buying wala case -> buy/not_buy
        {
            return dp[ind][buy] = max(-prices[ind]+funcmemo(ind+1, 0, fees, prices, n, dp), 0+funcmemo(ind+1, 1, fees, prices, n, dp));
        }
        if(buy==0) // selling wala case -> sell/not_sell
        {
            return dp[ind][buy] = max(+prices[ind]-fees + funcmemo(ind+1, 1, fees, prices, n, dp), 0+funcmemo(ind+1, 0, fees, prices, n, dp));
        }
        
        return dp[ind][buy];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int ans = funcmemo(0,1,fee,prices,n,dp);
        return ans;
    }
};