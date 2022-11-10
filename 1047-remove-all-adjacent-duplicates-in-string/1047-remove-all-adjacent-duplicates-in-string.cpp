// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/2798136/LeetCode-The-Hard-Way-Explained-Line-By-Line-(C%2B%2B-Python-Java-Go-Kotlin-Rust)
class Solution {
public:
    string removeDuplicates(string s) {
        // use string here instead of Stack<char>
        // so that we don't need to build the final string again
        string ans;
        for (auto c : s) {
            // if the current character is same as the last one in `ans`
            // then we cannot push it to `ans`
            // we remove the one in `ans`
            if (ans.size() && ans.back() == c) ans.pop_back();
            // otherwise, add the current character to `ans`
            else ans.push_back(c);
        }
        return ans;
    }
};