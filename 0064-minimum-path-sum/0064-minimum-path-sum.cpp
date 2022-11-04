class Solution {
public:
    int fmemo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // base case
        if(i==0 && j==0)
            return grid[0][0];
        // agar out of bound chala gaya toh
        if(i<0 || j<0)
            return 1e9;

        if(dp[i][j]!=-1) 
            return dp[i][j];

        int up = grid[i][j] + fmemo(i-1, j, grid, dp);
        int left = grid[i][j] + fmemo(i, j-1, grid, dp);

        dp[i][j] = min(up, left);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fmemo(n-1, m-1, grid, dp);
    }
};
