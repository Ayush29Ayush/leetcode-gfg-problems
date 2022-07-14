class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto element : nums)
            mp[element]++;
        
        int max = INT_MIN;
        int ans = 0;
        
        for(auto element : mp)
        {
            if(element.second>max)
            {
                max = element.second;
                ans = element.first;
            }    
        }
        return ans;
    }
};