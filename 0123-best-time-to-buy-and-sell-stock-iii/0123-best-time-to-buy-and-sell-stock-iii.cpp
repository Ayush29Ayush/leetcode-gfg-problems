class Solution {
public:  
    //! MEMOIZATION
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

        if(ind==n || cap==0) return 0; //base case

        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];

        int profit;

        if(buy==0)
        {   
            // We can either buy or not_buy the stock, then take the max
            profit = max(0 + getAns(Arr,n,ind+1,0,cap,dp), -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
        }

        if(buy==1)
        {   
            // We can eiter sell or not_sell the stock, then take the max
            profit = max(0 + getAns(Arr,n,ind+1,1,cap,dp), Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        
        int ans = getAns(prices,n,0,0,2,dp);
        return ans;
    }
};