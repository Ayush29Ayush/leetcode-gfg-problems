// RK ka solution
class Solution {
public:
//ALGO: KMP
    bool repeatedSubstringPattern(string s) {
        vector<int> dp(s.size()+1,0);//every dp[i] tells us that the character present on (i-1 )th index appeared before on (dp[i]-1) th index.
        //we're kind of trying to mark all the potential beginnings of the repeating substring whenever we encounter same characters at both start and end pointers
        int start = 0, end = 1;
        while(end<s.size())
        {
            if(s[end]==s[start]) dp[++end] = ++start; //we mark if same chars are at start and end, hoping this is the start of the repeating substring
            //if it is, then start and end would keep moving ahead, and chars at start and end would keep being the same till we reach the end of the string 
            else if(start==0) ++end; //if not even the first repeating substring has been found yet 
            else start = dp[start]; //whenever dissimilar characters at start and end, given start!=0,
            // then we re-initialise start to 0 in the hope of finding the repeating substring starting from 0
        }
        //s.size()-dp[s.size()] : denotes the size of the repeating substring
        return dp[s.size()]!=0 && s.size()%(s.size()-dp[s.size()])==0;
        //for repeating substring throughout the string, size of string should be divisible by the size of substring
    }
};