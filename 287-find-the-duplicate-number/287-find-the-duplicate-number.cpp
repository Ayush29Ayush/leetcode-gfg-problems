// Brute Force with sorting => Time Complexity:O(Nlogn + N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int answer;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                answer =  nums[i]; 
                break;
            }
        }
        
        return answer;
    }
};