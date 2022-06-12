// https://www.youtube.com/watch?v=7YqscdGIS6Y

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, current=0;
        unordered_set<int> set;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            // to shrink the sliding window
            while (set.find(nums[j]) != set.end()) {
                set.erase(nums[i]);
                current -= nums[i];
                i++;
            }
            set.insert(nums[j]);
            current += nums[j];
            ans = max(ans, current);
        }
        return ans;
    }
};