class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        total_rows = len(grid)
        total_cols = len(grid[0])
        
        state = [i for i in range(total_cols)]
        
        for i in range(total_rows - 1, -1, -1):
            newState = [1 for i in range(total_cols)]
            for j in range(total_cols):
                if grid[i][j] == 1:
                    if j + 1 < total_cols and grid[i][j + 1] == 1:
                        newState[j] = state[j + 1]
                    else:
                        newState[j] = -1
                else:
                    if j != 0 and grid[i][j - 1] == -1:
                        newState[j] = state[j - 1]
                    else:
                        newState[j] = -1
            state = newState.copy()
        
        return state