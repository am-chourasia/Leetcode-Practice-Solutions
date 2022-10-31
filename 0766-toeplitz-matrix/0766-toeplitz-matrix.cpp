class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int total_rows = matrix.size();
        int total_cols = matrix[0].size();
        
        for (int j = 0; j < total_cols; j++) {
            int elem = matrix[0][j];
            int row = 0;
            int col = j;
            while (row < total_rows and col < total_cols) {
                if (matrix[row][col] != elem) 
                    return false;
                row += 1;
                col += 1;
            }
        }
        
        for (int i = 1; i < total_rows; i++) {
            int elem = matrix[i][0];
            int row = i;
            int col = 0;
            while (row < total_rows and col < total_cols) {
                if (matrix[row][col] != elem) 
                    return false;
                row += 1;
                col += 1;
            }
        }
        
        return true;
    }
};