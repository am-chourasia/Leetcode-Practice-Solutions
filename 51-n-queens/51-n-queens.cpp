class Solution {
    vector<vector<string>> ans;
    int N;
    bool check(vector<string>& board, int row, int col){
        // upwards
        for(int i = row - 1; i >= 0; i--)
            if(board[i][col] == 'Q')
                return false;
        // upper left
        for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        // upper right
        for(int i = row - 1, j = col + 1; i >= 0 and j < N; i--, j++)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    void solve(int i, vector<string>& board){
        if(i >= N){
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < N; j++){
            if(check(board, i, j)){
                board[i][j] = 'Q';
                solve(i + 1, board);
                board[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N = n;
        solve(0, board);
        return ans;
    }
};