class Solution {
public:
    int arrangeCoins(int n) {
        long i = 1, sum = 0;
        while(sum <= n) 
        {
            sum += i;
            i++;
        }
        return i-1-1; // pehla -1 to adjust that last i++ and second -1 because we have to return the last row that was complete and thats the prev one.
    }
};