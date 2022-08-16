class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp(26);
        int ans = -1;
        
        for(auto i : s)
        {
            mp[i]++;
        }
        
        for(int i = 0; i<s.size(); i++)
        {
            if(mp[s[i]]==1)
            {
                ans = i;
                break;
            }
        }
        // for(auto i : mp)
        // {
        //     if(i.second==1)
        //     {
        //         ans = s.find(i.first);
        //         break;
        //     }
        // }
        
        return ans;
    }
};