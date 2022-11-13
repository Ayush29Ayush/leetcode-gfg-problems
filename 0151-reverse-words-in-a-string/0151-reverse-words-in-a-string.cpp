class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.length()-1;
        string ans;
        string temp;
        
        while (!isalpha(s[i]) && !isdigit(s[i]))
        {
            i++;
        }
        
        while(j>=i)
        {
            if(isalpha(s[j]) || isdigit(s[j]))
            {
                temp+=s[j];
                j--;
            }
            else if(s[j]==' ' && temp.empty())
            {
                j--;
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                temp.clear();
                j--;
            }
        }
        
        reverse(temp.begin(),temp.end());
        
        return (ans+temp);
    }
};