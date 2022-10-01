class Solution {
public:
    int reachNumber(int target) {
        int sum = 0;
        int steps = 0;
        
        target = abs(target);
        
        while(sum<target)
        {
            sum += steps;
            steps++;
        }
        
        while((sum-target)%2!=0)
        {
            sum = sum+steps;
            steps++;
        }
        
        return steps-1;
    }
};