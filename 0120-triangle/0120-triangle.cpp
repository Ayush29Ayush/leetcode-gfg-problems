//! STRIVER memoization code
class Solution {
public:
    int fmemo(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp)
    {
        //base case
        if(i==n-1)
            return triangle[n-1][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int down = triangle[i][j] + fmemo(i+1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + fmemo(i+1, j+1, triangle, n, dp);

        return dp[i][j] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fmemo(0,0,triangle,n,dp);
    }
};

// tabulation code written in my notion notes
