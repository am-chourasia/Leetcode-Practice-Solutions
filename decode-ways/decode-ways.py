class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 1:
            # if the only character is zero, no string can be formed
            return 1 if s[0] != '0' else 0 
        
        dp = [0] * (n+2)
        dp[n] = 1
        dp[n+1] = 0
        
        for i in range(n-1, -1, -1):
            if s[i] == '0':
                dp[i] = 0   # No string can be formed with this starting index
                # If the zero at this index is not lead by an appropriate character before it
                if i == 0 or s[i-1] >= '3' or s[i-1] == '0':
                    return 0
            elif (s[i] == '2' and i+1 < n and s[i+1] <= '6') or (s[i] == '1'):
                dp[i] = dp[i+1] + dp[i+2]
            
            else:
                dp[i] = dp[i+1]
        
        return dp[0]