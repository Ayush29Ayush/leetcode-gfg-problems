// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) {
//         int maxi_x = 0;
//         int maxi_y = 0;
        
//         for(int i = 0; i < points.size(); i++)
//         {
//             maxi_x = max(maxi_x, points[i][0]);
//             maxi_y = max(maxi_y, points[i][1]);
//         }
//         return (0.5 * maxi_x * maxi_y);
//     }
// };

// https://leetcode.com/problems/largest-triangle-area/discuss/122711/C%2B%2BJavaPython-Solution-with-Explanation-and-Prove
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0;
        for (auto &i : p)
            for (auto &j : p)
                for (auto &k : p)
            res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};