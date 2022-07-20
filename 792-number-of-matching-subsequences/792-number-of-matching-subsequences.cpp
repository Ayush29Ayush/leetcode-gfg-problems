// https://leetcode.com/problems/number-of-matching-subsequences/discuss/2306365/C%2B%2B-binarysearch-and-stuff

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charMap(26);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            charMap[s[i] - 'a'].push_back(i);
        }
        
        int ans = words.size();
        
        for(auto& word : words) {
            int last = -1;
            
            for(char c : word) {
                auto& cIndexes = charMap[c - 'a'];
                auto it = upper_bound(cIndexes.begin(), cIndexes.end(), last);
                if(it == cIndexes.end()) {
                    ans--;
                    break;
                } else {
                    last = *it;
                }
            }
        }
        
        return ans;
    }
};