class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        mini = triangle[n-1]
        
        row = n-2
        while row >=0:
            for i in range(row+1):
                mini[i] = min(mini[i], mini[i+1]) + triangle[row][i]
            row -= 1
        
        return mini[0]
                
        
        