class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        n = len(coins)
        dp = {}
        
        def recurse(i, target):
            if target == 0:
                return 1
            if i >= n:
                return 0
            if (i, target) in dp:
                return dp[i, target]
            if coins[i] > target:
                dp[i, target] = recurse(i+1, target)
            else:
                dp[i, target] = recurse(i+1, target) + recurse(i, target - coins[i])
            return dp[i, target]
    
        return recurse(0, amount)