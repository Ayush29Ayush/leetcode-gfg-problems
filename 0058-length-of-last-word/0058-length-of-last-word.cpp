class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i]!=' ')
                length++;
            if(s[i]==' ' && length>0)
                return length;
        }
        return length;
    }
};