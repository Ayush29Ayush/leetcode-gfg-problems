class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word3 = "";
        string word4 = "";
        // concatenate the strings
        for(auto i : word1)
            word3 += i;
        for(auto i : word2)
            word4 += i;
        // if equal return true else false
        return (word3 == word4);
    }
};