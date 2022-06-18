class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;                // counting frequency of elements
        for(auto [i, freq] : mp)
            if(freq == 1) return i;                // return element occuring once
        return -1;                                 // wont be reached
    }
};