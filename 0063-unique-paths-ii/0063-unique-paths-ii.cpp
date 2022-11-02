// Striver DP ques, refer notion notes if needed => DP9 
class Solution {
public:
    int fmemo(int i, int j, vector<vector<int> > &maze, vector<vector<int> > &dp) 
    {    
        // base case 
        
        if((i==0 && j == 0) && maze[i][j]==1)
            return 0;
        if(i==0 && j == 0)
              return 1;
        else if((i<0 || j<0) || maze[i][j]==1)
              return 0;

        if(dp[i][j]!=-1) 
              return dp[i][j];

      int up = fmemo(i-1,j,maze,dp);
      int left = fmemo(i,j-1,maze,dp);

      return dp[i][j] = (up+left);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return fmemo(m-1,n-1,obstacleGrid,dp);
    }
};