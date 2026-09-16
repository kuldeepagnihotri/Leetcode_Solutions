class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {
        // horizontal
        for(int j=0; j<9; j++){
            if(board[row][j] == digit) return false;
        }
        // vertical
        for(int i=0; i<9; i++){
            if(board[i][col] == digit) return false;
        }
        // 3x3 grid
        int sr_row = (row/3)*3;
        int sc_col = (col/3)*3;
        for(int i=sr_row; i<sr_row+3; i++){
            for(int j=sc_col; j<sc_col+3; j++){
                if(board[i][j] == digit) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true; // base case

        int nextRow = row, nextCol = col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }

        // place correct digit
        for(char digit='1'; digit<='9'; digit++){
            if(isSafe(board, row, col, digit)){
                board[row][col] = digit;
                if(helper(board, nextRow, nextCol)) return true;
                board[row][col] = '.'; // backtrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
