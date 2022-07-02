class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        mod = 1000000007
        horizontalCuts.append(h)
        horizontalCuts.sort()
        verticalCuts.append(w)
        verticalCuts.sort()
        
        maximumHeight = horizontalCuts[0]
        for i in range(1, len(horizontalCuts)):
            height = horizontalCuts[i] - horizontalCuts[i - 1]
            maximumHeight = max(maximumHeight, height)
        
        maximumWidth = verticalCuts[0]
        for i in range(1, len(verticalCuts)):
            width = verticalCuts[i] - verticalCuts[i - 1]
            maximumWidth = max(maximumWidth, width)
        
        maximumArea = (maximumHeight * maximumWidth) % mod
        return maximumArea