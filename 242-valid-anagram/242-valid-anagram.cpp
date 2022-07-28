class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<int,int> mp1, mp2;
        
        for(auto i : s)
            mp1[i]++;
        
        for(auto i : t)
            mp2[i]++;
        
        for(int i = 0; i<s.size(); i++)
        {
            if(mp1[s[i]]!=mp2[s[i]])
                return false;
        }
        
        return true;
    }
};