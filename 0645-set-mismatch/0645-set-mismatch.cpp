// https://leetcode.com/problems/set-mismatch/discuss/2734799/C%2B%2B-oror-Set-Mismatch-oror-Simple-andand-Easy-andand-Unique-Solution-oror-Explained
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    //sum of elements on nums
    int initialSum = accumulate(nums.begin(), nums.end(), 0);

    //put the element of nums into set to remove the duplicate number
    set<int> s;
    for(auto &i: nums){
        s.insert(i);
    }

    //sum of elements of the set
    int sum = accumulate(s.begin(), s.end(), 0);

    //difference of initialSum and sum will give us the repeated number
    int repeatedNum = initialSum - sum;

    //sum of all the natural numbers from 1 to n
    int n = nums.size() + 1;

    //subtracting the sum of elements in set i.e. sum from the sum of the natural numbers will give us the missing number
    int missingNum = n * (n-1)/2 - sum;

    return {repeatedNum, missingNum};
}
};