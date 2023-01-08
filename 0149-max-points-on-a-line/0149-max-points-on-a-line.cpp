// refer this video => https://www.youtube.com/watch?v=Y8_WxLKYQ6Q
// MY DISCUSS FORUM POST => https://leetcode.com/problems/max-points-on-a-line/discuss/3016360/Easiest-C%2B%2B-solution-with-detailed-explanation
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
            return n;
        
        int maxi = 2;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int count=2;
                for(int k=0; k<n; k++)
                {
                    if(k!=i && k!=j)
                    {
                        if((points[j][1]-points[i][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[j][0]-points[i][0]))
                            count++;
                    }
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};