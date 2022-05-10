class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi = 0;
        
        for(auto i:s)
        {
            int temp = i, cnt = 0;
            if(s.find(temp-1)!=s.end())
            {
                continue;
            }
            while(s.find(temp)!=s.end())
            {
                cnt++;
                temp++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};