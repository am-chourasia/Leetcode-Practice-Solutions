class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        count = 0
        costs.sort()
        
        for cost in costs:
            if coins < cost:
                break
            count += 1
            coins -= cost
        
        return count