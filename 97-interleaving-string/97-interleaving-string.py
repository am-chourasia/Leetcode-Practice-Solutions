class Solution:
    def isInterleave(self, s1: str, s2: str, s: str) -> bool:
        len1, len2, len3 = len(s1), len(s2), len(s)
        if len3 != len1 + len2:
            return False
        
        dp = [[None for j in range(len2 + 1)] for i in range(len1 + 1)]
        
        def isPossible(i, j, k):
            if dp[i][j] is not None:
                return dp[i][j]
            
            if k is len3:
                dp[i][j] = True
                return True
            
            if i < len1 and s[k] is s1[i]:
                if isPossible(i + 1, j, k + 1):
                    dp[i][j] = True
                    return True
                
            if j < len2 and s[k] is s2[j]:
                if isPossible(i, j + 1, k + 1):
                    dp[i][j] = True
                    return True
            
            dp[i][j] = False
            return False
        
        return isPossible(0, 0, 0)