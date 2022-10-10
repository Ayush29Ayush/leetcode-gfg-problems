class Solution {
public:
    string breakPalindrome(string s)
    {
        int n=s.size();
        if(n==0||n==1)
            return "";
    
        for(int i=0;i<n;i++)
            {
                // n%2==1 bhi kar sakte they
				if(n&1 && i==n/2)  //if n is odd like "aba" nothing will happen when we change 'b' to some other char that why we ignore it
                {
                    continue;
                }
                if(s[i]!='a')
                {
                    s[i]='a';
                    return s;
                }
            }
            s[n-1]='b';
        return s;
    }
};