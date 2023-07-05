class Solution {
public:
    int n;
    
    // step3
    int findMax(vector<int>& nums, int skip_idx)
    {
        int currLength = 0;
        int maxLength = 0;
        
        for(int i=0; i<n; i++)
        {
            if(i==skip_idx)
                continue;
            
            if(nums[i]==1)
            {
                currLength++;
                maxLength = max(maxLength,currLength);
            }
            else
            {
                currLength = 0;
            }
        }
        // step4
        return maxLength;
    }
    
    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        
        // step5     nums = [1,1,1] output = 2 i.e (n-1)
        int countZero = 0;        
        
        // step1
        for(int i=0; i<n; i++)
        {
            // step2
            if(nums[i]==0)
            {
                countZero++; // step6
                result = max(result, findMax(nums,i));
            }
        }
        
        // step7
        if(countZero==0)
            return n-1;
        
        return result;
    }
};