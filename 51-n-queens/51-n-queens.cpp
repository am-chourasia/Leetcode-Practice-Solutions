class Solution {
    vector<vector<string>> ans;
    int N;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N = n;
        solve(0, board);
        return ans;
    }
    bool check(vector<string>& board, int i, int j){
        for(int k = 0; k < N; k++)
            if(board[i][k] == 'Q' or board[k][j] == 'Q')
                return false;
        int k = i - 1;
        int r = 1;
        while(k >= 0){
            if(j + r < N and board[k][j + r] == 'Q')
                return false;
            if(j - r >= 0 and board[k][j - r] == 'Q')
                return false;
            r++;
            k--;
        }
        k = i + 1;
        r = 1;
        while(k < N){
            if(j + r < N and board[k][j + r] == 'Q')
                return false;
            if(j - r >= 0 and board[k][j - r] == 'Q')
                return false;
            k++;
            r++;
        }
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
};