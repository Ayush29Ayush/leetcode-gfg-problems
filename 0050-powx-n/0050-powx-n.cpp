class Solution {
public:
    
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power_of_x = abs(n);
        
        while(power_of_x>0)
        {
            // if power is odd
            if(power_of_x%2==1)
            {
                ans = ans*x;
                power_of_x = power_of_x - 1;
            }
            else if(power_of_x%2==0)
            {
                x = x*x;
                power_of_x = power_of_x / 2;
            }
        }
        
        if(n<0)
            return (double)1/(double)ans;
        
        return (double)ans;
    }
};