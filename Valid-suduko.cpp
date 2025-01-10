class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            set<char> rows, cols, diagonals;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' && rows.count(board[i][j])) {
                    return false;
                }
                rows.insert(board[i][j]);
                if(board[j][i] != '.' && cols.count(board[j][i])) {
                    return false;
                }
                cols.insert(board[j][i]);
                int diagRow = 3*(i/3)+(j/3);
                int diagCol = 3*(i%3)+(j%3);
                if(board[diagRow][diagCol] != '.' && diagonals.count(board[diagRow][diagCol])) {
                    return false;
                }
                diagonals.insert(board[diagRow][diagCol]);
            }
        }
        return true;
    }
};