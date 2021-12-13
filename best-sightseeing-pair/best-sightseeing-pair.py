class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        
        # values[i] + values[j] + i - j == (values[i] + i) + (values[j] - j)
        
        n = len(values)
        maxi = values[n-1] - (n-1)
        ans = 0
        
        for i in range(n-2,-1,-1):
            ans = max(ans, values[i] + i + maxi)
            maxi = max(values[i] - i, maxi)
            
        return ans