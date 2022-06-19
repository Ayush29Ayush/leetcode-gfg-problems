// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168430/C%2B%2B-easy-approach-3-liner

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        
        for(int i = 1; i<=10;i++)
        {
            int res = i*k;
            if(res%10==num%10 && res<=num)
            {
                return i;
            }
        }
        return -1;
    }
};