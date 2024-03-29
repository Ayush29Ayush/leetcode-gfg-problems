class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        
        for(auto x : nums)
        {
            if(x==0)
                return 0;
            else if(x<0)
                sign = -sign;
        }
        
        return sign;
    }
};