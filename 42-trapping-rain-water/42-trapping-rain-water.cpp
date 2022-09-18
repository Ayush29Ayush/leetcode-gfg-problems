// https://leetcode.com/problems/trapping-rain-water/discuss/2590012/C%2B%2B-or-Brute-or-Precomputation-or-Two-Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_stored = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    water_stored += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    water_stored += right_max - height[right];
                }
                right--;
            }
        }
        return water_stored;
    }
};