class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s=="") 
            return t[0];
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i=0;
        for(; i<s.size(); i++){
            if(t[i] != s[i]) 
                break;
        }
        
        return t[i];
    }
};