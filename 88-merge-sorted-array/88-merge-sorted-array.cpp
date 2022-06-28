class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m); // removes the additional zeroes at end of num1
        nums1.insert(nums1.end(), nums2.begin(), nums2.end()); // vector_name.insert(position, iterator1, iterator2)
        sort(nums1.begin(), nums1.end()); // sorts the merged array
    }
};