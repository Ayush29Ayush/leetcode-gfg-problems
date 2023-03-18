// https://leetcode.com/problems/maximum-subarray/discuss/2193128/c-solution-beats-100-optimized-tc-on-kadanes-algorithm
// KADANES ALGO
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        
        for(auto i : nums)
        {
            sum += i;
            
            maximum = max(maximum,sum);
            
            if(sum<0)
                sum = 0;
        }
        
        return maximum;
    }
};