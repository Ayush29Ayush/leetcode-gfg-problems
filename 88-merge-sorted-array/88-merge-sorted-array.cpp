class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums(m + n, 0);
        int k = 0, i = 0, j = 0;
        if (n == 0)
            return;
        while (i < m && j < n)
        {

            if (nums1[i] < nums2[j])
                nums[k++] = nums1[i++];

            else
                nums[k++] = nums2[j++];
        }

        while (i < m)
            nums[k++] = nums1[i++];
        while (j < n)
            nums[k++] = nums2[j++];

        nums1 = nums;
    }
};