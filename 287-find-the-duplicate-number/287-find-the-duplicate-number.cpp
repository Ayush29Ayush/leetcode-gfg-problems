// https://leetcode.com/problems/find-the-duplicate-number/discuss/1892872/C%2B%2B-oror-Algorithm-oror-4-Approaches-oror-Binary-Search-oror-Brute-Force-oror-cnt-array-oror-map

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
	// for github repository link go to my profile.
};