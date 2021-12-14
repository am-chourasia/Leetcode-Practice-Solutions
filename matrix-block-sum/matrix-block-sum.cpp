class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++)
                mat[i][j] += mat[i][j-1];
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++)
                mat[i][j] += mat[i-1][j];
        }
        //        .
        //        .
        // . . . .(p, q) . . . . (p, b)
        //         .               .
        //         .               .
        //         .               .
        // . . . .(a, q) . . . . (a, b)
        int a, b, p, q;
        vector<vector<int>> ans(n, vector<int>(m));  
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a = min(i + k, n-1);
                b = min(j + k, m-1);
                p = max(-1, i-k-1);
                q = max(-1, j-k-1);
                int sum = mat[a][b];
                if(p!=-1 and q!=-1)
                    sum = sum + mat[p][q] - mat[p][b] - mat[a][q];
                else if(p != -1)
                    sum = sum - mat[p][b];
                else if(q != -1)
                    sum = sum - mat[a][q];
                ans[i][j] = sum;
            }
        }
        
        return ans;
    }
};