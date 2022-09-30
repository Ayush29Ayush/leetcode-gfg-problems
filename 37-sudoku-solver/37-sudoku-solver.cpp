//we are using bool solve because we need only first soln for which sudoku is solved.
class Solution {
public:
    bool isPossible(int row,int col,char c,vector<vector<char>>& board,int n){
        
        for(int i=0;i<n;i++){
            //row check
            if(board[row][i] == c){
                return false;
            }
            //col check
            if(board[i][col] == c){
                return false;
            }
            //matrix check 
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c){
                return false;
            }
        }
        //means no same value found in same row,col and matrix.
        return true;
    }
    
    //ye aage tak call marega aur jabtak possible hoga chalta rahega agar koi bhi 1-9 me nhi milta possible to return false.
    bool solve(vector<vector<char>>& board){
        int n = board[0].size();
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
                if(board[row][col] == '.'){
                    
                    for(char c='1';c<='9';c++){
                        if(isPossible(row,col,c,board,n)){
                            board[row][col] = c;
                            //recrsive call
                            if(solve(board) == true){
                                return true;
                            }
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                            
                        }
                    }
                    //matlab '.' me koi bhi number fit nhi hora ,agar hota to true return kardeta,nhi kia true matlab false karna hai return aur backtrack kardena.
                    return false;
                }
            }
        }
        //means all spaces are filled.
        return true;
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};