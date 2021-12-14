class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        
        # dp[i] will be storing the minimum number of coins required for i value.
        dp = [0 for i in range(amount + 1)]
        dp[0] = 0

        for i in range(1, amount + 1):
            dp[i] = sys.maxsize

        for i in range(1, amount + 1):
            for j in range(n):
                if coins[j] <= i:
                    included = dp[i - coins[j]]
                    if included != sys.maxsize and included + 1 < dp[i]:
                        dp[i] = included + 1

        if dp[amount] == sys.maxsize:
            return -1

        return dp[amount]