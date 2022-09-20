class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int combination1 = nums[n-1]*nums[n-2]*nums[n-3];
        int combination2 = nums[0]*nums[1]*nums[n-1];
        
                
        return max(combination1,combination2);
    }
};