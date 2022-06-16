class Solution:
    def canMeasureWater(self, cap1: int, cap2: int, target: int) -> bool:
        
        if(cap1 > cap2):
            cap1, cap2 = cap2, cap1
            
        if cap1 + cap2 < target:
            return False
        
        seen = set()
        queue = deque()
        queue.append((0, 0))
        
        while queue:
            a, b = queue.popleft()
            if a + b == target:
                return True
            
            states = set()
            
            states.add((0, b))
            states.add((a, 0))
            states.add((cap1, b))
            states.add((a, cap2))
            remain = cap1 - a
            states.add((a + min(b, remain), max(0, b - remain)))
            remain = cap2 - b
            states.add((max(0, a - remain), b + min(a, remain)))
            
            for state in states:
                if state not in seen:
                    queue.append(state)
                    seen.add(state)
            
        return False