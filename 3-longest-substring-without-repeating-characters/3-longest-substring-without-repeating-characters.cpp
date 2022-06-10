// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/2133061/O(n)-Solution-in-C%2B%2B-oror-Sliding-Window-oror-HashMaps

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        
        map<char, int> mp;
        int curr=0, res=0;
        for(int i=0;i<s.size();i++) {
			//i-curr, gives us the count of characters in our current window (curr is starting of our window)
            res=max(res, i-curr);
			
			//If the character is present and its index is present in current window, we update our current window...
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=curr) {
                curr = mp[s[i]]+1;
            }
            mp[s[i]] = i;
        }
		
		//This is to handle the case when the longest substring is at the end our string, in this case we wont enter the if condition and hence curr variable won't be updated...
        if(res<s.size()-curr) return s.size()-curr;
		
        return res;
    }
};