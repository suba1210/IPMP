// bool isSafe1(int row, int col, vector < string > board, int n) {
//     // check upper element
//     int duprow = row;
//     int dupcol = col;

//     while (row >= 0 && col >= 0) {
//     if (board[row][col] == 'Q')
//         return false;
//     row--;
//     col--;
//     }

//     col = dupcol;
//     row = duprow;
//     while (col >= 0) {
//     if (board[row][col] == 'Q')
//         return false;
//     col--;
//     }

//     row = duprow;
//     col = dupcol;
//     while (row < n && col >= 0) {
//     if (board[row][col] == 'Q')
//         return false;
//     row++;
//     col--;
//     }
//     return true;
// }

// void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
//     if (col == n) {
//     ans.push_back(board);
//     return;
//     }
//     for (int row = 0; row < n; row++) {
//     if (isSafe1(row, col, board, n)) {
//         board[row][col] = 'Q';
//         solve(col + 1, board, ans, n);
//         board[row][col] = '.';
//     }
//     }
// }

class Solution {
public:
    void solve(int col, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<string>& board, vector<vector<string>>& result){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            // instead of this 'if' condition we might also use 'isSafe' function
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, n, leftRow, lowerDiagonal, upperDiagonal, board, result);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        string s(n,'.');
        vector<int> leftRow(n,0), lowerDiagonal((2*n)-1,0), upperDiagonal((2*n)-1,0);
        solve(0, n, leftRow, lowerDiagonal, upperDiagonal, board, result);
        return result;
    }
};