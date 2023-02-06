// the first half n elements are x and the second half n elements are y
// we can iterate n times and push nums[i] and nums[i + n]
// since the distance for each x_i and y_i is just `n`
class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      // push x_1 .. x_n
      ans.push_back(nums[i]);
      // push y_1 .. y_n
      ans.push_back(nums[i + n]);
    }
    return ans;
  }
};