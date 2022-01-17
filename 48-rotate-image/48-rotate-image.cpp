class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        //taking transpose of a matrix
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //need to swap 1st and last colms element to get the desired ans
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n/2; j++){
                
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
        
    }
};