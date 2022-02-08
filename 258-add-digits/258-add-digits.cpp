class Solution {
    public:
    int addDigits(int num) {
        int sum = 0;
        while(num>0){
            int digit = num%10;
            sum+=digit;
            num/=10;
        }
        //base case
        if((sum/10)<1)
            return sum;
        
        return addDigits(sum);
    }
};