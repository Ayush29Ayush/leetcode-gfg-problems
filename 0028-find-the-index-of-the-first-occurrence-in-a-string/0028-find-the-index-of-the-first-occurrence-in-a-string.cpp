class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        
        if(n1<n2)
            return -1;
        if(n2==0)
            return 0;
        
        // Find position of string needle in haystack
        int found = haystack.find(needle);
        
        // Check if position is -1 or not
        // npos actually means until the end of the string.
        // This means ki string ke end pe ab point kar raha hai i.e string mein koi position mila hi nahi i.e needle is not in haystack
        if(found == string::npos)
            return -1;
        else
            return found;
    }
};