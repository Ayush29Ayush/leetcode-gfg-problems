// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//         int number = 0;
//         vector<int> ans;
//         for(int i=0; i<num.size(); i++)
//         {
//             number = number*10 + num[i];
//         }
        
//         int number1 = (number+k);
        
//         while(number1!=0)
//         {
//             int rem = (int)number1%10;
//             ans.push_back(rem);
//             number1 = number1/10;
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i=num.size()-1;i>=0;i--){
            num[i] += k;
            k = num[i]/10;
            num[i] %= 10;
        }
        while(k > 0){
            num.insert(num.begin(), k%10);
            k /= 10;
        }
        return num;
    }
};