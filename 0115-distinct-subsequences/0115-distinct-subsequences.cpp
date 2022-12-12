//! STRIVER DP 32
class Solution {
public:
    //! MEMOIZATION
    int countUtil(string &s1, string &s2, int ind1, int ind2,vector<vector<int>>& dp){
        // base case
        // agar s2 hi exhaust ho gaya that means match mil gaya hai
        if(ind2<0)
            return 1;
        // agar s1 hi exhaust ho gaya and match nahi mila then return 0
        if(ind1<0)
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2]){
            int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
            int stay = countUtil(s1,s2,ind1-1,ind2,dp);

            return dp[ind1][ind2] = (leaveOne + stay);
        }

        else{
            return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
        }
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return countUtil(s,t,n-1,m-1,dp);
    }
};