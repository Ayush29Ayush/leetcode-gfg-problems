//! using RECURSION
// class Solution {
// public:
//     int fib(int n) {
//         //Base Case
//         if(n==0)
//             return 0;
//         if(n==1)
//             return 1;
        
//         // Recurrence Relation
//         int ans = fib(n-1)+fib(n-2);
        
//         return ans;
//     }
// };

//! using DP
class Solution {
public:
    int fib(int n) {
        int ans[n+2];
        
        ans[0] = 0;
        ans[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            ans[i] = ans[i-1] + ans[i-2];
        }
        
        return ans[n];
        
    }
};