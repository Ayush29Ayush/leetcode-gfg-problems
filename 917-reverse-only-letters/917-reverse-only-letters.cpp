// https://leetcode.com/problems/reverse-only-letters/discuss/2170511/c-solution-2-pointer-approach-0ms-faster-than-100-tc-on-sc-o1
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) left++; // Skip non-alpha characters
            while (left < right && !isalpha(s[right])) right--; // Skip non-alpha characters
            swap(s[left++], s[right--]);
        }
        return s;
    }
};