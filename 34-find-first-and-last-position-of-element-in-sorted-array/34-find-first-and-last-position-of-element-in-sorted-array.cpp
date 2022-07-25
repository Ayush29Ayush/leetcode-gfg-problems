class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // nums = [5,7,7,8,8,10], target = 8
        
        auto low = lower_bound(nums.begin(),nums.end(),target); // iterator at 3
        auto up = upper_bound(nums.begin(),nums.end(),target); // iterator at 4
        
        if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
    
        int start = low - nums.begin();
        int end = up - nums.begin() - 1;
        return {start , end};
    }
};