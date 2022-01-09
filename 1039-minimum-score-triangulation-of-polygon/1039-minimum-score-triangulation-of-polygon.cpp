class Solution {
    int calculate(vector<int>& values, int start, int end, vector<vector<int>>& dp){
        if(start >= end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        int mini = INT_MAX;
        for(int k = start; k < end; k++){
            int left = calculate(values, start, k, dp);
            int right = calculate(values, k+1, end, dp);
            int val = left + right + values[start-1] * values[k] * values[end];
            mini = min(mini, val);
        }
        return dp[start][end] = mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return calculate(values, 1, n-1, dp);
    }
};