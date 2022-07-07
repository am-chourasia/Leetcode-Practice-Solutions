class Solution:
    def isInterleave(self, s1: str, s2: str, s: str) -> bool:
        len1, len2, len3 = len(s1), len(s2), len(s)
        if len3 != len1 + len2:
            return False
        
        dp = [[None for j in range(len2 + 1)] for i in range(len1 + 1)]
        dp[len1][len2] = True
        
        k = len3 - 1
        for i in range(len1 - 1, -1, -1):
            dp[i][len2] = dp[i + 1][len2] and s[k] is s1[i]
            k -= 1
        
        k = len3 - 1
        for j in range(len2 - 1, -1, -1):
            dp[len1][j] = dp[len1][j + 1] and s[k] is s2[j]
            k -= 1
        
        for i in range(len1 - 1, -1, -1):
            for j in range(len2 - 1, -1, -1):
                k = i + j
                dp[i][j] = s[k] is s1[i] and dp[i + 1][j] or \
                           s[k] is s2[j] and dp[i][j + 1]
            
        return dp[0][0]