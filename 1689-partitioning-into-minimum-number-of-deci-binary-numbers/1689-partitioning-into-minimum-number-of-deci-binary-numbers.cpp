// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/discuss/2202970/C%2B%2B-oror-DETAILED_EXPLAINED-oror-BEATS-100-oror-TC-greater-O(n)

class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int max_digit_in_string = 0;
        
        for(auto element : n)
        {
            // convert the string number into integer number by subtracting the ascii value.
            int digit = element - '0';
            max_digit_in_string = max(max_digit_in_string,digit);
        }
        
        return max_digit_in_string;
    }
};