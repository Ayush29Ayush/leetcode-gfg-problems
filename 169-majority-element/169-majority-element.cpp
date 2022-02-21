/*Explanation:
1. Basic idea is that we will sort the array
2. The element which is present more than size/2 time must appear at the mid of the vector.
3. Return the middle element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the vector
        return nums[nums.size()/2];   // middle element will be the most frequent Element
    }
};