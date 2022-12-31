// why return low? => https://leetcode.com/problems/search-insert-position/discuss/1596479/C%2B%2B-or-3-Solutions-or-Well-explained-with-example-and-concise-solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     
        int low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] > target) high = mid-1;
            
            else low = mid+1;
        }
        return low;
    }
};