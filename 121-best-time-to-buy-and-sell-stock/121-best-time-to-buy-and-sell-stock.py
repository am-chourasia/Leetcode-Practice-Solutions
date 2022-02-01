class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi = prices[-1]
        ans = 0
        i = len(prices)-2
        
        while i >= 0:
            ans = max(ans, maxi - prices[i])
            maxi = max(maxi, prices[i])
            i -= 1
        
        return ans
            
        