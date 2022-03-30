class Solution:
    def findMin(self, nums: List[int]) -> int:
        length = len(nums)
        start = -1; end = length - 1
        
        while start + 1 < end:
            mid = (start + end) // 2
            if nums[mid] < nums[end]:
                end = mid
            else:
                start = mid
        
        return nums[end]