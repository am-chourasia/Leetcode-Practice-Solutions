class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        n = len(grid1)
        m = len(grid1[0])
        
        def isSubIsland(i, j):
            if i < 0 or i >= n or j < 0 or j >= m:
                return True
            
            if grid2[i][j] != 1:    # no need to include either visited or water
                return True
            
            grid2[i][j] = 2          # mark as visited
            top = isSubIsland(i - 1, j)     # check the top direction
            left = isSubIsland(i, j - 1)    # check the left direction
            right = isSubIsland(i, j + 1)   # check the right direction
            down = isSubIsland(i + 1, j)    # check the down direction

            return right and down and top and left and grid1[i][j] == 1
        
        ans = 0
        
        for i in range(n):
            for j in range(m):
                if grid2[i][j] is 1 and isSubIsland(i, j):
                        ans += 1
                    
        return ans