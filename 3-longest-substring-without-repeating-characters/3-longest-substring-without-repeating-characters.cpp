// https://www.youtube.com/watch?v=dvXyTOYVxB8&t=151s

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256]= {0}; // because here ASCII value will be taken from a(97) to z(122)
        int left = 0; // starting index of the window
        int right = 0; // ending index of the window
        int ans = 0; // length of the longest substring without repeating characters
        
        while(right<s.length())
        {
            count[s[right]]++;
            
            while(count[s[right]]>1)
            {
                count[s[left]]--;
                left++;
            }
            
            ans = max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};