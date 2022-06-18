//! Refer this   ->    https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/1587270/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-%2B-Hashmap-%2B-XOR-%2B-Linear-%2B2-Binary-Search

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int ans = 0;
//         for(int i = 0; i<nums.size();i++)
//         {
//             ans = ans ^ nums[i];
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(auto i : nums) mp[i]++;                // counting frequency of elements
//         for(auto [i, freq] : mp)
//             if(freq == 1) return i;                // return element occuring once
//         return -1;                                 // wont be reached
//     }
// };

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto a : mp)
        {
            if(a.second==1)
            {
                return a.first;
            }
        }
        return -1;
    }
};

// for(int i = 0;i<nums.size();i++)
//         {
//             if(mp[nums[i]]==1)
//             {
//                 return i;
//             }
//         }