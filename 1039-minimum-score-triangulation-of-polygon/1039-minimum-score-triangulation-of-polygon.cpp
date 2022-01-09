class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        // dp[i][j] : 
        // minimum score for triangle formed with (i-1)th and jth vertex,
        // with the third vertex in between i-1 and j
        
        for(int points = 2; points < n; points++){ // points selected at each iteration
            for(int i = 1; i + points - 1 < n; i++){ // the endpoint j should be less than n
                int j = i + points - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k<j; k++){
                    int value = dp[i][k] + dp[k+1][j];
                    value += (values[i-1] * values[k] * values[j]);
                    dp[i][j] = min(dp[i][j], value);
                }
                cout << i << " " << j << "\t" << dp[i][j] << endl;
            }
        }
        
        return dp[1][n-1];
    }
};