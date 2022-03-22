// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/1871653/C%2B%2B-oror-Dry-Run-oror-Easy-oror-Simple-and-Short-oror-O(N)

class Solution {
public:
    string getSmallestString(int n, int k) {
        
        // initialising string of length n with all 'a';
        string str(n,'a');
        
        // as all 'a' are 1 and therefore we have subtract there sum;
        k -= n;
        
        while( k > 0)
        {
            // turning rightmost digit , 'a' into 'z' ('a' + 25, or 'a' + k)
            // while k is positive.
            str[--n] += min(25,k);
            k -= min(25,k);
        }
        
        return str;
    }
};