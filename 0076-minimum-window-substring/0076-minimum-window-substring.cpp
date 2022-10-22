class Solution {
public:
    bool check(int charMap[58], int window[58]) {
        for (int i=0; i<58; i++) if (charMap[i] > window[i]) return false;
        return true;
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int charMap[58] = {0}, window[58] = {0}, minLen = INT_MAX, start = -1;
        for (char &c : t) charMap[c-'A']++;
        string res = "";
        for (int i=0,j=0; j<s.size(); j++) {
            window[s[j]-'A']++;
            while (window[s[i]-'A'] > charMap[s[i]-'A'] && i<j) {
                window[s[i]-'A']--;
                i++;
            }
            if (s.size() == 0 || j-i+1 < minLen) {
                if (check(charMap, window)) {
                    minLen = j-i+1;
                    start = i;
                }
            }
        }

        return start == -1 ? "" : s.substr(start,minLen);
    }
};