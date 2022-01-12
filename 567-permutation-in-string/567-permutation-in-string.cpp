class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.length()>s2.length()) return 0;
        string hash1 = "0000000000000000000000000000000";
        for(int i=0; i<s1.length(); i++)
            hash1[s1[i]-'a']++;
        for(int i=0; i<s2.length()-s1.length()+1; i++)
        {
            string hash2 = "0000000000000000000000000000000";
            for(int j=i; j<s1.length()+i; j++)
                hash2[s2[j]-'a']++;
            if(hash1==hash2) return 1;
        }
        return 0;
    }
};