class Solution {
    int rows;
    int cols;
    
    boolean isValidIndex(int i, int j){
        if(i < 0 || i >= rows)
            return false;
        if(j < 0 || j >= cols)
            return false;
        return true;
    }
    
    int aliveNeighbours(int[][] board, int i, int j){
        int count = 0;
        int row = i - 1;
        for(int k = 1; k <= 3; k++){
            int col = j - 1;
            for(int l = 1; l <= 3; l++){
                if(row != i || col != j){
                    if(isValidIndex(row, col)){
                        int value = Math.abs(board[row][col]);
                        if(value == 1)
                            count++;
                    }
                }
                col++;
            }
            row++;
        }
        return count;
    }
    
    void update(int[][] board, int i, int j){
        int alive = aliveNeighbours(board, i, j);
        if(board[i][j] == 1 && (alive < 2 || alive > 3))
            board[i][j] = -1;
        else if(board[i][j] == 0 && alive == 3)
            board[i][j] = 2;
    }
    
    void sanitize(int[][] board){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
    }
    
    public void gameOfLife(int[][] board) {
        rows = board.length;
        cols = board[0].length;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                update(board, i, j);
        }
        
        sanitize(board);
    }
}