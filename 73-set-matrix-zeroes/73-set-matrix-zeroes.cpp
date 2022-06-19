// https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = true;
        // int rows = sizeof(matrix)/sizeof(matrix[0]);
        int rows = matrix.size();
        // int cols = sizeof(matrix[0]/sizeof(matrix[0][0]));
        int cols = matrix[0].size();
        
        
        // iterate from forward
        for(int i = 0; i < rows; i++)
        {
            if(matrix[i][0]==0) col0 = false;
            for(int j = 1; j < cols; j++)
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        // iterate from backward
        for(int i = rows-1; i >= 0; i--){
            for(int j = cols-1; j >= 1; j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};