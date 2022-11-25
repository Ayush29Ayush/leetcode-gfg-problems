//instead of using different visited matrix we mark the given board itself for keeping track of visited and backtrack while all four conditions are got and if false then put the picked character back to board[i][j].
class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& board,string &word,int n,int m,int k){
        //base case
        if(k == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i > n-1 || j > m-1 || board[i][j] == '.'){
            return false;
        }
        if(board[i][j] != word[k]){
            return false;
        }
        
        //mark visited
        board[i][j] = '.';
        
        //left call
        bool left = solve(i,j-1,board,word,n,m,k+1);
        //ans.pop_back();
        bool right = solve(i,j+1,board,word,n,m,k+1);
        bool up = solve(i-1,j,board,word,n,m,k+1);
        bool down = solve(i+1,j,board,word,n,m,k+1);
        
        if(left || right || up || down){
            return true;
        }
        
        //backtrack jo character uthaya hai wapas rakdo.
        board[i][j] = word[k];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != '.'){
                    bool res = solve(i,j,board,word,n,m,0);
                    if(res == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};