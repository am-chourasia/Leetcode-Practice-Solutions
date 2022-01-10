class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = rec1
        p1, q1, p2, q2 = rec2
        
        # if one rectangle is completely left to the other:
        if x2 <= p1 or p2 <= x1:
            return False
        
        # if one rectangle is completely above other:
        if y2 <= q1 or q2 <= y1:
            return False
        
        return True