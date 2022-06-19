class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.size()-1;
        while (start < end) {
            while (start < end && !isalpha(s[start])) start++; // Skip non-alpha characters
            while (start < end && !isalpha(s[end])) end--; // Skip non-alpha characters
            swap(s[start++], s[end--]);
        }
        return s;
    }
};