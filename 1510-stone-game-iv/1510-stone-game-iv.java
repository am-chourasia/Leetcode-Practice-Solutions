class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];
        // true -> winning state;
        // false -> losing state;
        // if another winning state can be achieved from any state, that state is a winning state;
        dp[0] = false;
        
        for(int i = 1; i <= n; i++){
            for(int squaredNumber = 1; i - squaredNumber * squaredNumber >= 0; squaredNumber++){
                int square = squaredNumber * squaredNumber;
                if(dp[i - square] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
}