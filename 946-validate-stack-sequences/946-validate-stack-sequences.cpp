// https://leetcode.com/problems/validate-stack-sequences/discuss/1853109/C%2B%2B-oror-2-Approaches-oror-Explained-With-Algorithm-oror-Easy-and-Simple

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s ;   // an empty stack
        int j = 0;
        for(int i= 0; i<pushed.size(); ++i)
        {
            s.push(pushed[i]);
            
			// check if pushed values is next to pe popped out.
            while(!s.empty() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
		// if stack is empty means sequence is correct.
        return s.empty();
    }
};