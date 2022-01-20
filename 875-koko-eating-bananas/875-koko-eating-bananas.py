class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = 10 ** 9
        
        def canEat(k):
            hours = 0
            for bananas in piles:
                hours += math.ceil(bananas / k)
                if hours > h:
                    return False
            return True
        
        while low < high:
            mid = (low + high) // 2
            if canEat(mid):
                high = mid
            else:
                low = mid + 1
        
        return low
        
        