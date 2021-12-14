class Solution {
    public int numSquares(int n) {
        // 1 = 1, 2 = 1 + 1, 3 = 1 + 1 + 1
        if(n<4)
            return n;
        
        int[] dp = new int[n+1];
        
        // every number can be represented as sum of ones
        for(int i=0; i<=n; i++)
            dp[i] = i;
        
        for(int i=0; i<=n; i++)
            for(int j=1; j*j <= i; j++)
                dp[i] = Math.min(dp[i], 1 + dp[i-j*j]);
        
        return dp[n];
    }
}