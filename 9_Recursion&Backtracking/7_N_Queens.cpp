class Solution {
public:
    void solve(int col, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<string>& board, vector<vector<string>>& result){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
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
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0), lowerDiagonal((2*n)-1,0), upperDiagonal((2*n)-1,0);
        solve(0, n, leftRow, lowerDiagonal, upperDiagonal, board, result);
        return result;
    }
};