// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/2612407/C%2B%2B-or-Diagram-or-Related-Problems
class Solution {
public:
    
    int numberOfBits(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};