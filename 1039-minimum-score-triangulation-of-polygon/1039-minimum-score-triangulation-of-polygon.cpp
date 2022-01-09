class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        // dp[i][j] : 
        // minimum score for triangle formed with ith and jth vertex,
        // with the third vertex in between i and j
        
        for(int len = 2; len < n; len++){
            for(int i = 1; i + len - 1 < n; i++){
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k<j; k++){
                    int value = dp[i][k] + dp[k+1][j];
                    value += (values[i-1] * values[k] * values[j]);
                    dp[i][j] = min(dp[i][j], value);
                }
            }
        }
        
        return dp[1][n-1];
    }
};