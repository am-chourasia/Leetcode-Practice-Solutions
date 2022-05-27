class Solution {
    bool checkRow(vector<string>& board, char symbol){
        for(int row = 0; row < 3; row++){
            if(board[row][0] == symbol and 
               board[row][1] == symbol and 
               board[row][2] == symbol)
                return true;
        }
        return false;
    }
    bool checkCol(vector<string>& board, char symbol){
        for(int col = 0; col < 3; col++){
            if(board[0][col] == symbol and 
               board[1][col] == symbol and 
               board[2][col] == symbol)
                return true;
        }
        return false;
    }
    bool checkMajorDiagonal(vector<string>& board, char symbol){
        int count = 0, row = 0, col = 0;
        while(row < 3){
            if(board[row][col] == symbol)
                count++;
            row++, col++;
        }
        return count == 3;
    }
    bool checkMinorDiagonal(vector<string>& board, char symbol){
        int row = 2, col = 0;
        int count = 0;
        while(row >= 0){
            if(board[row][col] == symbol)
                count++;
            row--, col++;
        }
        return count == 3;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        bool x_winning = isWinning(board, 'X');
        bool o_winning = isWinning(board, 'O');
        
        if(x_winning and o_winning)
            return false;
        
        int x = 0, o = 0;
        for(string& row : board){
            for(char symbol : row){
                if(symbol == 'O')
                    o++;
                else if(symbol == 'X')
                    x++;
            }
        }
                
        if(x_winning and o + 1 != x)
            return false;
        if(o_winning and o != x)
            return false;
        
        return x == o or x == o + 1;
    }
    bool isWinning(vector<string>& board, char symbol){
        if(checkRow(board, symbol))
            return true;
        if(checkCol(board, symbol))
            return true;
        if(checkMinorDiagonal(board, symbol))
            return true;
        if(checkMajorDiagonal(board, symbol))
            return true;
        return false;
    }
};