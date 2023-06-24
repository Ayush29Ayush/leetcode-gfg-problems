/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Zyzs3AuqPRw
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/tallest-billboard/
*/


//Approach-2 (We can't take t[21][5001][5001] because it will casue Memory Limit Exceed
//Instead of storing s1 and s2, we can store (s1-s2) i.e. diff
//i.e. t[n+1][max diff we can get]
/*
  To avoid negative diff, we will use same trick like we did in Leetcode-1027. Longest Arithmetic Subsequence (Adding an offset)
*/
class Solution {
public:
    int n; 
    int t[21][10003];
    int solve(vector<int>& rods, int i, int diff) {

        if (i == n) {
            if (diff == 0)
                return 0;

            return INT_MIN;
        }
        
        if( t[i][diff+5000] != -1)
            return  t[i][diff+5000];
        
        int ans = 0;

        int nothing     = solve(rods, i + 1 , diff);
        int in_rod_1    = rods[i] + solve(rods, i + 1 , diff + rods[i]);
        int not_in_rod1 = rods[i] + solve(rods, i + 1 , diff - rods[i]);

        return t[i][diff+5000] = max({nothing, in_rod_1, not_in_rod1});
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(rods, 0, 0)/2;
    }
};