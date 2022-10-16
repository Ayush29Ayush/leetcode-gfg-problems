// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int n = nums.size();
        
//         // push all the nums with there freq in map
//         for(int i=0; i<n; i++)
//         {
//             mp[nums[i]]++;
//         }
        
//         // now search from 1 to n
//         for(int i=1; i<n+1; i++)
//         {
//             if(n==1)
//                 return nums[0]+1;
            
//             // agar number nahi mila then thats the ans
//             if(mp.find(i)==mp.end())
//                 return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
        {
            while(nums[i]>0 and nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        
        return n+1;
    }
};