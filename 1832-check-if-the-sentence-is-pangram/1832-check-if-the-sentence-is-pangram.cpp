class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> uset;
        
        for(int i=0; i<sentence.size(); i++)
        {
            uset.insert(sentence[i]);
        }
        
        if(uset.size()==26)
            return true;
        else
            return false;
    }
};