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