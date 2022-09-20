class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //sort to get ascending order so that largest numbers are at the end and smallest or negatives will be at start
        //Ex - {2,-3,3,-1,4} => {-3,-1,2,3,4}
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // combination1 will be product of largest 3 numbers
        int combination1 = nums[n-1]*nums[n-2]*nums[n-3];
        // combination2 => lets take this test case as demo
        // prod of 2 negatives will make it positive and then multiplying that with the largest element can give the                largest product possible
        // Ex -> {-10,-9,1,2,3}
        int combination2 = nums[0]*nums[1]*nums[n-1];
        
        // now check which combination is maximum
        return max(combination1,combination2);
    }
};