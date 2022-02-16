class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [sys.maxsize] * (n + 1)
        dp[n] = 0
        
        for i in range(n-1, -1, -1):
            dp[i] = stoneValue[i] - dp[i+1]
            if i + 1 < n:
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2])
            if i + 2 < n:
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3])
        
        if dp[0] == 0:
            return "Tie"
        if dp[0] > 0:
            return "Alice"
        return "Bob"