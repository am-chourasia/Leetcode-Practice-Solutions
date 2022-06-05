class Solution {
    int count;
    int N;
    bool check(vector<int>& board, int row, int col){
        // upwards
        for(int i = row - 1; i >= 0; i--)
            if(isSet(board[i], col))
                return false;
        // upper right
        for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
            if(isSet(board[i], j))
                return false;
        // upper left
        for(int i = row - 1, j = col + 1; i >= 0 and j < N; i--, j++)
            if(isSet(board[i], j))
                return false;
        return true;
    }
    void solve(int i, vector<int>& board){
        if(i >= N){
            count++;
            return;
        }
        for(int j = 0; j < N; j++){
            if(check(board, i, j)){
                set(board[i], j);
                solve(i + 1, board);
                unset(board[i], j);
            }
        }
    }
    bool isSet(int& n, int j){
        if((n & (1 << j)) != 0)
            return true;
        return false;
    }
    void set(int& n, int j){
        n = (n | (1 << j));
    }
    void unset(int& n, int j){
        n = n ^ (1 << j);
    }
public:
    int totalNQueens(int n) {
        vector<int> board(n, 0);
        N = n;
        count = 0;
        solve(0, board);
        return count;
    }
};