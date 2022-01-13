class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        
        start, end = points[0]
        arrows = 1
        
        for i in range(1, len(points)):
            istart, iend = points[i]
            if istart > end:
                arrows += 1
                start, end = istart, iend
            else:
                start = max(start, istart)
                end = min(end, iend)
        
        return arrows
                