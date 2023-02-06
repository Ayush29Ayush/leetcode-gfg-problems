class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        vector<vector<int>> board(8, vector<int>(8, 0)); // create a 8*8 board and initialize all elements with 0
        for (auto q : queens) {
            board[q[0]][q[1]] = 1; // mark the position of queens with 1
        }
        
        // check the elements on the left side of king
        for (int i = king[0] - 1; i >= 0; i--) {
            if (board[i][king[1]] == 1) { // if it is a queen
                res.push_back({i, king[1]}); // add to result
                break;
            }
        }
        
        // check the elements on the top side of king
        for (int i = king[0] + 1; i < 8; i++) {
            if (board[i][king[1]] == 1) {
                res.push_back({i, king[1]});
                break;
            }
        }
        
        // check the elements on the right side of king
        for (int i = king[1] - 1; i >= 0; i--) {
            if (board[king[0]][i] == 1) {
                res.push_back({king[0], i});
                break;
            }
        }
        
        // check the elements on the bottom side of king
        for (int i = king[1] + 1; i < 8; i++) {
            if (board[king[0]][i] == 1) {
                res.push_back({king[0], i});
                break;
            }
        }
        
        // check the elements on the left-top diagonal side of king
        for (int i = king[0] - 1, j = king[1] - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                res.push_back({i, j});
                break;
            }
        }
        
        // check the elements on the left-bottom diagonal side of king
        for (int i = king[0] - 1, j = king[1] + 1; i >= 0 && j < 8; i--, j++) {
            if (board[i][j] == 1) {
                res.push_back({i, j});
                break;
            }
        }
        
        // check the elements on the right-top diagonal side of king
        for (int i = king[0] + 1, j = king[1] - 1; i < 8 && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                res.push_back({i, j});
                break;
            }
        }
        
        // check the elements on the right-bottom diagonal side of king
        for (int i = king[0] + 1, j = king[1] + 1; i < 8 && j < 8; i++, j++) {
            if (board[i][j] == 1) {
                res.push_back({i, j});
                break;
            }
        }
        return res;
    }
};