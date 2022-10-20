class Solution {
public:
    string intToRoman(int num) {
        // I simply use a hash map to store the mapping between Roman and Integer. Then do the greedy search in order to build the roman number
        vector<int> arr = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> map = {
                {1000, "M"}, {900, "CM"},
                {500, "D"},{400, "CD"}, {100, "C"},
                {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
                {5, "V"}, {4, "IV"}, {1, "I"}
        };
        int idx = 0;
        string res;
        while (num > 0) {
            while (num < arr[idx])
                idx++;
            res += map[arr[idx]];
            num -= arr[idx];
        }
        return res;
    }
};