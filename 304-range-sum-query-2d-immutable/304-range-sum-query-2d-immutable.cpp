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
    
    int sumRegion(int p, int q, int a, int b) {
        int sum = mat[a][b];
        p--, q--;
        cout << a << " " << b << " " << p << " " << q << endl;
        if(p!=-1 and q!=-1)
            sum = sum + mat[p][q] - mat[p][b] - mat[a][q];
        else if(p != -1)
            sum = sum - mat[p][b];
        else if(q != -1)
            sum = sum - mat[a][q];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */