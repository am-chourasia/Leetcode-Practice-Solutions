class Solution:
    def findPaths(self, n: int, m: int, maxMove: int, startRow: int, startColumn: int) -> int:
        mod = 1000000007
        dp = [[[None for moves in range(maxMove + 1)] for col in range(m)] for row in range(n)]
        
        def countPaths(i, j, moves):
            if i < 0 or j < 0 or i >= n or j >= m:
                return 1
            if moves == 0:
                return 0
            if dp[i][j][moves] is not None:
                return dp[i][j][moves]
            
            dp[i][j][moves] = (countPaths(i + 1, j, moves - 1) \
                               + countPaths(i, j + 1, moves - 1) \
                               + countPaths(i - 1, j, moves - 1) \
                               + countPaths(i, j - 1, moves - 1)) % mod
            return dp[i][j][moves]
        
        return countPaths(startRow, startColumn, maxMove);
        
        