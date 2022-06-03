class NumMatrix {
    int n;
    int m;
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        mat.resize(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                mat[i][j] = matrix[i][j];
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++)
                mat[i][j] += mat[i][j-1];
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++)
                mat[i][j] += mat[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = mat[row2][col2];
        row1--, col1--;
        
        if(row1!=-1 and col1!=-1)
            sum = sum + mat[row1][col1] - mat[row1][col2] - mat[row2][col1];
        else if(row1 != -1)
            sum = sum - mat[row1][col2];
        else if(col1 != -1)
            sum = sum - mat[row2][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */