//concept is using queue but can be done without it as we will be making start from 0 and check balance if it goes less than 0 means gas values occuring less than that value can not be start so put upto that balance in deficit and compue futher. If in the end balance is greater than deficit or equal means that start is possible answer.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;
        
        for(int i=0;i<gas.size();i++){
            balance += gas[i]-cost[i];
            //checking if it is deficit .
            if(balance<0){
                deficit += balance;
                balance = 0;
                //start cannot be less than this ith value as before elements must hava also contributed in further elements .
                start = i+1;
            }
        }
            
            if(deficit + balance < 0){
                return -1;
            }
        
        return start;
    }
};