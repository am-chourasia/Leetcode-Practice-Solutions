class Solution {
    public int coinChange(int[] coins, int required) {
        
        int n = coins.length;
        int[] dp = new int[required + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        
        for(int amount = 1; amount <= required; amount++){
            for(int coin : coins){
                int pre = amount - coin;
                if(pre >= 0 && dp[pre] >= 0){
                    if(dp[amount] == -1)
                        dp[amount] = dp[pre] + 1;
                    else
                        dp[amount] = Math.min(dp[amount], dp[pre] + 1);
                }
            }
        }
        
        return dp[required];
    }
}