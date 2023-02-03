// simulate and add each character to the corresponding row
// go down -> reach bottom -> go up -> reach top -> go down ...
class Solution {
public:
    string convert(string s, int n) {
        // edge case
        if (n == 1) return s;
        vector<string> rows(n);
        // j is the index to track which rows a character should be added to
        // d is the direction: -1 means go up, 1 means go down
        int j = 0, d = 1;
        for (int i = 0; i < s.size(); i++) {
            // add the current character to corresponding row
            rows[j] += s[i];
            // if it reaches to the last row, we need to go up
            if(j == n - 1) d = -1;
            // if it reaches to the first row, we need to go down
            else if(j == 0) d = 1;
            // move j pointer
            j += d;
        }
        // rows would look like below in the first example
        // ['PAHN', 'APLSIIG', 'YIR']
        // we use `accumulate` to build the final answer (in C++ 20, it takes O(n) only)
        return accumulate(rows.begin(), rows.end(), string{});
    }
};