class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                             ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                             "...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> ans;
        
        for(auto word : words)
        {
            string temp;
            for(auto ch : word)
            {
                temp += morse[ch-'a'];
            }
            ans.insert(temp);
        }
        
        return ans.size();
    }
};