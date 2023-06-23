/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=S3ocpdBL-7Y
    Company Tags                  : GOOGLE
    Leetcode Link                 : https://leetcode.com/problems/longest-arithmetic-subsequence/
*/

//Approach-2 (Just solve it like Longest Increasing Subsequence)
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> t(n, vector<int>(1001,0));
        //t[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                t[i][diff] = t[j][diff] > 0 ? t[j][diff] + 1 : 2;
                
                result      = max(result, t[i][diff]);
            }
        }

        return result;
    }
};