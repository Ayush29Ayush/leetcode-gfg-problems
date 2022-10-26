//! it will automatically contact the police if two adjacent houses were broken into on the same night.
//! this means ek hi baar mein first and last wala consider nahi kar sakte
//! so there will be 2 calls, one without first and one without last element and take the max of those two because it is asked in the ques
class Solution {
public:
    // memoization code from house robber 1
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
        vector<int> temp1, temp2;
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        for(int i = 0; i<n; i++)
        {
            // without first element
            if(i!=0)
                temp1.push_back(nums[i]);
            // without the last element
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        
        int n1 = temp1.size();
        int n2 = temp2.size();
        vector<int> dp1(n1,-1);
        vector<int> dp2(n2,-1);
        
        int ans1 = solveMem(temp1, n1-1, dp1);
        int ans2 = solveMem(temp2, n2-1, dp2);
        
        return max(ans1,ans2);
    }
};