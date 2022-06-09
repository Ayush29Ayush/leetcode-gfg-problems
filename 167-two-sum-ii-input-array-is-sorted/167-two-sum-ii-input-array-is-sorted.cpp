//! https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/261140/C%2B%2B-with-explanation-Clear-and-simple

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target) return {i+1,j+1};
            else if(sum>target) j--;
            else i++;
        }
        return {}; // not found
    }
};