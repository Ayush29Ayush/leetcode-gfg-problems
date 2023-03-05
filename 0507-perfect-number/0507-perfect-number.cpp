class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        vector<int> divisor;
        for(int i=1; i<=num/2; i++)
        {
            if(num%i==0)
                divisor.push_back(i);
        }
        
        int sum = 0;
        for(int i=0; i<divisor.size(); i++)
        {
            sum += divisor[i];
        }
        
        if(sum==num)
            return true;
        
        return false;
    }
};