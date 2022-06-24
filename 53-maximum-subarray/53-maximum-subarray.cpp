class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        
//         for(int i=0; i<nums.size();i++)
//         {
//             sum += nums[i];
            
//             if(maximum<sum)
//                 maximum = sum;
            
//             if(sum<0)
//                 sum=0;
//         }
        
        // Using iterator for traversal
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