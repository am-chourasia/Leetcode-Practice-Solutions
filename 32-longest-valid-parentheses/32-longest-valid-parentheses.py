class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        if n is 0 or n is 1:
            return 0
        
        ans = 0
        dp = [0 for i in range(n)]
        
        for i in range(1, n):
            if s[i] is ')':
                if s[i - 1] is '(':
                    prev = i - 2
                    dp[i] = 2
                    if prev >= 0:
                        dp[i] += dp[prev]
                else:
                    prev = i - dp[i - 1] - 1
                    if prev >= 0 and s[prev] is '(':
                        dp[i] = dp[i - 1] + dp[prev - 1] + 2
                ans = max(ans, dp[i])
                
        return ans
        
                    
                
                