class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size())
            return false;
        
        // char first[] = s.toCharArray();
        // char second[] = t.toCharArray();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        // sort(first);
        // sort(second);
        
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        
        return true;
    }
};