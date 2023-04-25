// refer this if needed for DRY RUN => https://www.youtube.com/watch?v=qOhKCAm9-sw&t=242s
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        
        if(*s.begin()==0)
            return s.size()-1;
        else
            return s.size();
    }
};