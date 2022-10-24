//same as Maximum Sum of Non-Adjacent Elements problem on code studio.
class Solution {
public:
    // recursion.
    int solve(vector<int> &nums,int n){
        //base case
        if(n < 0){
            return 0;  
        }
        if(n == 0){
            return nums[0];
        }
        
        int pick = nums[n] + solve(nums,n-2);
        int nonpick = 0 + solve(nums,n-1);
        
        int ans = max(pick,nonpick);
        return ans;
        
    }
    
    // memoization
    int solveMem(vector<int>& nums,int n,vector<int>& dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int pick = nums[n] + solveMem(nums,n-2,dp);
        int nonpick = 0 + solveMem(nums,n-1,dp);
        
        dp[n] = max(pick,nonpick);
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        //return solve(nums,n-1);
        return solveMem(nums,n-1,dp);
    }
};