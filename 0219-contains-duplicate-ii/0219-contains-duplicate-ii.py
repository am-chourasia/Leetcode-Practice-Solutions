class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        k += 1
        distinct = set(nums[:k])
        
        if k >= n:
            return n > len(distinct)
        
        for i in range(k, n):
            distinct.discard(nums[i-k])
            distinct.add(nums[i])
            if len(distinct) != k:
                return True
        
        return False
        