class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return n
        
        dp = [1] * (n)
        a = b = c = 0
        
        for i in range(1, n):
            dp[i] = min(2 * dp[a], 3 * dp[b], 5 * dp[c])
            if dp[i] == 2 * dp[a]:  a += 1
            if dp[i] == 3 * dp[b]:  b += 1
            if dp[i] == 5 * dp[c]:  c += 1
        
        return dp[n-1]