// //! Using sets
// class Solution {
// public:
//     bool checkIfPangram(string sentence) {
//         unordered_set<char> uset;
        
//         for(int i=0; i<sentence.size(); i++)
//         {
//             uset.insert(sentence[i]);
//         }
        
//         if(uset.size()==26)
//             return true;
//         else
//             return false;
//     }
// };

//! Using map
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // unordered_map<char,int> mp;
        vector<int> freq(26,0);
        
        for(int i = 0; i<sentence.size(); i++)
        {
            // mp[sentence[i]]++;
            freq[sentence[i]-'a']++;
        }
        
        // for(auto i : mp)
        // {
        //     if(i.second==0)
        //         return false;
        // }
        
        for(int i = 0; i<freq.size(); i++)
        {
            if(freq[i]==0)
                return false;
        }
        
        return true;
    }
};