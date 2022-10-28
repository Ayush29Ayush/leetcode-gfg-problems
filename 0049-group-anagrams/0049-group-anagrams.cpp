class Solution {
public:
    // all anagrams in the same group would have the same frequency for each character
    // e.g. ["nat","tan"] - both have 1 'a', 1't', and 1'n'
    // in other words, we can group the anagrams by their frequencies
    // another observation is that after sorting all anagrams in the group,
    // they would have the same result (because they have same frequency of each word)
    // ["nat","tan"] -> "ant"
    // so we can also group the anagrams by its sorted key
    // below it the group by sorted key version
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we need to a hashmap to store an array of the anagrams
        // with its sorted string as the key
        // e.g. "ant":  ["nat","tan"]
        unordered_map<string, vector<string>> m;
        // iterate each string
        for(auto& x : strs) {
            // since we need to know the original value,
            // we copy `x` to `t` for sorting
            string t = x;
            // sort it to make the key
            sort(t.begin(), t.end());
            // push the orginal the value under its sorted key
            m[t].push_back(x);
        }
        // build the final anwser
        vector<vector<string>> ans;
        // x.second is the array of the anagrams under the key `x.first`
        for(auto& x : m) ans.push_back(x.second);
        return ans;
    }
};