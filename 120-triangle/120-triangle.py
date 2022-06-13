class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        
        for row in range(n - 2, -1, -1):
            for i in range(row+1):
                triangle[row][i] += min(triangle[row + 1][i], triangle[row + 1][i+1])
        
        return triangle[0][0]
        