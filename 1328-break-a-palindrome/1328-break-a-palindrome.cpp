// why i==n/2 is used ???
// when i==n/2 then
// i is at mid and the length is odd
// "aabaa" if you character 'b' to some other character then it is still Palindrome, no need to check on that index that's why I put a continue statement.
// "abba" but in this, you change the character to mid-index then it is not palindrome

// why s[n-1]='b'; is used ???
// because 'a' is the smallest character. if we get a character other than the 'a' then we replace it with 'a'
// and this is for corner case s[n-1]='b'
// if your string contains character only 'a' then we have only a way to replace the last character with 'b' to remove its palindrome property
// eg:
// intput string : "aaaaaaaaaa"
// to remove its palindrome property we need to replace a character but after replacing the character string must be lexicographically smaller that's why s[n-1]='b'
// output :"aaaaaaaaab"

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