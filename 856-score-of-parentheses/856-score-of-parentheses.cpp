// https://leetcode.com/problems/score-of-parentheses/discuss/1856417/C%2B%2B-oror-Explained-With-Algorithm-oror-0ms-oror-100-oror-Easy-and-Simple

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        int ind = 0;
        
        for(auto i : s)
        {
			// if we find open parenthesis
			// push the current score into the stack
            if(i == '(')
            {
                st.push(ind);
				// reset the score to 0
                ind = 0;
            }
            else // if we find close parenthesis
            {
                ind = st.top() + max(ind*2 ,1);
                st.pop();
            }
                
        }
        return ind;
        
    }
};