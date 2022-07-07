class Solution:
    def isInterleave(self, s1: str, s2: str, s: str) -> bool:
        len1, len2, len3 = len(s1), len(s2), len(s)
        if len3 != len1 + len2:
            return False
        
        dp = [None for j in range(len2 + 1)]
        dp[len2] = True
        
        k = len3 - 1
        for j in range(len2 - 1, -1, -1):
            dp[j] = dp[j + 1] and s[k] is s2[j]
            k -= 1
        
        p = len3 - 1
        for i in range(len1 - 1, -1, -1):
            dp[len2] = dp[len2] and s[p] is s1[i]
            for j in range(len2 - 1, -1, -1):
                k = i + j
                dp[j] = s[k] is s1[i] and dp[j] or \
                        s[k] is s2[j] and dp[j + 1]
            p -= 1
            
        return dp[0]