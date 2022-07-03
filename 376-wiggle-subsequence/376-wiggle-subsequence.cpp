// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if(nums.size()==1)
//             return 1;
        
//         int prev_diff = nums[1] - nums[0];
        
//         int counter = (prev_diff != 0) ? 2 : 1;
        
//         for(int i=2; i<nums.size(); i++)
//         {
//             int curr_diff = nums[i] - nums[i-1];
            
//             if((curr_diff > 0 && prev_diff <= 0) || (curr_diff < 0 && prev_diff >= 0))
//             {
//                 counter++;
//                 prev_diff = curr_diff;
//             }
//         }
        
//         return counter;
//     }
// };

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int peak = 1, valley = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                peak=valley + 1;
            else if(nums[i]<nums[i-1])
                valley = peak + 1;
        }
        return max(peak, valley);
    }
};