class Solution {
public:
    static bool compare(string &a, string &b)
    {
        // agar a ka size hi chota hai b ke size se means a ka value is smaller than b ka value and vica-versa
        if (a.size() != b.size()) return a.size() < b.size();
        // batao ki a b se chota hai ki nahi
        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size()-k];
    }
};