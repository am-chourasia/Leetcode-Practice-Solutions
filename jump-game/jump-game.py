class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reach = 0
        for i in range(n-1):
            if i > reach:
                break
            if nums[i] + i > reach:
                reach = nums[i] + i
        
        return reach >= n - 1