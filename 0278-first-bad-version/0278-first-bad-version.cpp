// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// https://leetcode.com/problems/first-bad-version/discuss/1454609/C%2B%2B-Simple-and-Short-Solution-O(log(n))-0ms-Faster-than-100
class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};