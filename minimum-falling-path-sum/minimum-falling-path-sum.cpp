class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> dp(m), temp(m);
        
        for(int j=0; j<m; j++)
            dp[j] = matrix[0][j];
        
        for(int i = 1; i<n; i++){
            for(int j=0; j<m; j++){
                int t = dp[j];
                if(j > 0 && t > dp[j-1])
                    t = dp[j-1];
                if(j+1 < m && t > dp[j+1])
                    t = dp[j+1];
                temp[j] = matrix[i][j] + t;
            }
            dp = temp;
        }
        
        int ans = dp[0];
        for(int j=0; j<m; j++)
            ans = min(ans, dp[j]);
        return ans;
    }
};