// lets take target = 5


// sum after 1st move = 1
// sum after 2nd move = 3
// sum after 3rd move = 6 so stop here
        
//till 3rd move, sum will be 1+2+3 but since we surpassed the target, we need some negative numbers in our sum
// 1-2+3 will be same as 1+2+3 - 2*(2)
// we need this relation to be equal to TARGET
// so if we need 1+2+3 - 2*(2) = TARGET
// we conclude SUM - TARGET = 2*X 
// so the difference should be divisible by 2
        

class Solution {
public:
    int reachNumber(int target) {
        
        int sum = 0;
        int steps = 0;
        
        // mirror image of positive side
        target = abs(target);
        
        // step1 : get sum just greater that TARGET
        while(sum<target)
        {
            sum += steps;
            steps++;
        }
        
        // step2 : now try to get this relation satisfied
        while((sum-target)%2!=0)
        {
            sum = sum+steps;
            steps++;
        }
        
        // yeh ek step aage nikal gaya because of steps++ of last traversal of while loop so ans = steps-1
        return steps-1;
    }
};