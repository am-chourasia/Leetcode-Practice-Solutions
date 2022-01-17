class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        maxi, k = 0, 0
        
        for n in nums:
            if n is 1:
                k += 1
            else:
                k = 0
            maxi = max(maxi, k)
        
        return maxi