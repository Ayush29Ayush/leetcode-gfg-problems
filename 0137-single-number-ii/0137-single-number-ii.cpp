/*
    YOUTUBE VIDEO for reference   : https://www.youtube.com/watch?v=LK0c7tCzKmM
    Company Tags                  : Google, Amazon, Microsoft, Ola Cabs, Qualcomm
    Leetcode Link                 : https://leetcode.com/problems/single-number-ii/
*/

//Approach-1
/*
    Simply maintain a unordered_map. 
    Find the element having frequency 1
    Space Complexity = O(n)
    Time Complexity = O(n)
*/
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> mp;
        
//         for(auto i : nums)
//             mp[i]++;
        
//         for(auto x : mp)
//             if(x.second==1)
//                 return x.first;
        
//         return 0;
//     }
// };

//Approach-2
/*
    Sort + Smart Traversal
    Time - O(nlogn)
    Space - No extra space
*/
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
        
//         for(int i=1; i<n-1; i++)
//         {
//             if(nums[i-1]!=nums[i] && nums[i+1]==nums[i])
//                 return nums[i-1];
//             if(nums[i-1]==nums[i] && nums[i+1]!=nums[i])
//                 return nums[i+1];
//         }
        
//         return nums[0];
//     }
// };

//Approach - 3 (Time Complexity : O(32*n))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for(int i = 0; i<32; i++) {
            int temp = (1 << i);
            
            int countOne  = 0;
            int countZero = 0;
            
            for(int &num : nums) {
                if((num&temp) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
            }
            
            if(countOne % 3 == 1) {
                result = (result | temp);
            }
            
        }
        
        return result;
    }
};