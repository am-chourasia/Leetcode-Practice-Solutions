class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<int> dp(m);
        for(int j=0; j<m and obstacleGrid[0][j] != 1; j++)
            dp[j] = 1;
        
        for(int i=1; i<n; i++){
            if(obstacleGrid[i][0] == 1)
                dp[0] = 0;
            for(int j=1; j<m; j++){
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] = dp[j] + dp[j-1];
            }
        }
        
        return dp[m-1];
    }
};