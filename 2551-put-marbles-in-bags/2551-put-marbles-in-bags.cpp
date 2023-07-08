// for reference =>  https://www.youtube.com/watch?v=L-KWU8W3OqE

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;
        
        // step1
        vector<int> pairSum(m,0);
        
        // step2
        for(int i=0; i<m; i++)
        {
            pairSum[i] = weights[i]+weights[i+1];
        }
        
        // step3
        sort(pairSum.begin(), pairSum.end());
        
        // step4
        long maxSum = 0;
        long minSum = 0;
        
        for(int i = 0; i<k-1; i++) {
            minSum += pairSum[i];
            maxSum += pairSum[n-i-2];
        }
        
        return maxSum-minSum;
    }
};