class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        mini = triangle[n-1]
        
        for row in range(n - 2, -1, -1):
            for i in range(row+1):
                mini[i] = min(mini[i], mini[i+1]) + triangle[row][i]
        
        return mini[0]
                
        
        