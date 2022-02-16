class Solution {
    int[][] dp;
    int len;
    int calculate(int i, int m, int[] piles){
        if(i >= len)
            return 0;
        if(dp[i][m] != Integer.MAX_VALUE)
            return dp[i][m];
        int total = 0;
        int ans = Integer.MIN_VALUE;
        for(int j = 0; j < 2 * m; j++){
            if(i + j < len)
                total += piles[i + j];
            ans = Math.max(ans, total - calculate(i + j + 1, Math.max(m, j + 1), piles));
        }
        return dp[i][m] = ans;
    }
    public int stoneGameII(int[] piles) {
        len = piles.length;
        dp = new int[len + 1][2 * len + 1];
        for(int i = 0; i < len + 1; i++){
            dp[i] = new int[2 * len + 1];
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        int difference = calculate(0, 1, piles);
        int totalSum = Arrays.stream(piles).sum();
        int ans = (difference + totalSum)/2;
        return ans;
    }
}