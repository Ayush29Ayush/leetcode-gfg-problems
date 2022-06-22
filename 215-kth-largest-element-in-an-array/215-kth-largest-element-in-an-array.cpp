// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/2180777/C%2B%2B-solution-oror-Simple-oror-Optimized-Solution-oror-Sorting

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()-k];
    }
};