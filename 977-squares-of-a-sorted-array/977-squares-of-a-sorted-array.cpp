// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++) {
//             nums[i] = nums[i]*nums[i];
//         }
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

//! T.C -> O(N)
//! S.C -> O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int start = 0;
        int end = n-1;
        
        for(int i = 0; i<n; i++)
        {
            if(abs(nums[start])<=abs(nums[end]))
            {
                arr[n-i-1] = nums[end]*nums[end]; 
                end--;
            }
            else if(abs(nums[start])>=abs(nums[end]))
            {
                arr[n-i-1] = nums[start]*nums[start]; 
                start++;
            }
        }
        
        return arr;
    }
};