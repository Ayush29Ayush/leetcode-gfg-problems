class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int result = 0;
        int number = 0;
        
        int n = s.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
            }
            if(c == '-') {
                // number completed.
                // update result
                result += (sign) * (number);
                number = 0;
                sign = -1;
            }
            if(c == '+') {
                // number completed
                // update result
                result += (sign) * (number);
                number = 0;
                sign = 1;
            }
            if(c == '(') {
                // number completed, result updated already before when we encountered +/- before opening bracket
                st.push(result);
                st.push(sign); // so that sign remains at the top (signifies sign before opening bracket was encountered)
                result = 0; // building result between brackets from scratch
                sign = 1;
            }
            if(c == ')') {
                // number is completed
                // update result
                result += (sign) * (number);
                number = 0;
                result *= st.top(); // multiplying with sign before opening bracket
                st.pop();
                result += st.top(); // result constructed before current context.
                st.pop();
            }
        }
        
        
        // last no space character in case is a number itself , we need to use the number also.
        result += (sign) * number;
        
        return result;
    }
};