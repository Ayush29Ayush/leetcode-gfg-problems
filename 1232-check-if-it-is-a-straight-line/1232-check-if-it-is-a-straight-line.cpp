// [[0,0],[0,1],[0,-1]]  runtime error: division by zero (solution.cpp)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int row = coordinates.size();
        // int col = coordinates[0].size();
        
        // slope = y2-y1/x2-x1
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        
        // now trying y2-y1/x2-x1 == y3-y2/x3-x2. If this doesn't work then try y3 - origin/x3 - origin.
        // origin here means 0th coordinates.
        for(int i=2; i<row; i++)
        {
            int dy_i = coordinates[i][1] - coordinates[i-1][1];
            int dx_i = coordinates[i][0] - coordinates[i-1][0];
            
            // [[0,0],[0,1],[0,-1]]  runtime error: division by zero (solution.cpp)
            // if(dy_i/dx_i != dy/dx)
            //     return false;
            
            if(dy_i*dx != dy*dx_i)
                return false;
        }
        
        return true;        
    }
};