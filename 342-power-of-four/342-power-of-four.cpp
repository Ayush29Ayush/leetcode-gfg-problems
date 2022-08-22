class Solution {
public:
    bool isPowerOfFour(int n) {
        int ans = 1;
        
        for(int i = 0; i<=30; i++)
        {
            // if ans aur n same hai then return true
            if(ans==n)
                return true;
            
            // varna ans ko baaki 4 ke multiple banao and match karate jao
            if(ans<INT_MAX/4)
                ans = ans * 4;
        }
        return false;
    }
};