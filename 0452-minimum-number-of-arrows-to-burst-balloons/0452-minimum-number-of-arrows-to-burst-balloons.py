class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        start = end = -(2 ** 31 + 1)
        count = 0
        
        for (xstart, xend) in points:
            if xstart > end:
                count += 1
                end = xend
            end = min(end, xend) 
            start = max(start, xstart)
        
        return count