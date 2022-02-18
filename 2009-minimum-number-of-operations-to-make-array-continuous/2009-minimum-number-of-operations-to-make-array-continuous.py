class Solution:
    def minOperations(self, nums: List[int]) -> int:
        originalLength = len(nums)
        nums = sorted(list(set(nums)))
        length = len(nums)
        ans = originalLength - 1
        
        for left in range(length):
            target = nums[left] + (originalLength - 1)
            right = bisect.bisect_right(nums, target, left, length)
            withinWindow = right - left
            ans = min(ans, originalLength - withinWindow)
        
        return ans
                        