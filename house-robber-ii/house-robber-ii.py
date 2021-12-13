class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 3:
            return max(nums)
        
        dp_2 = nums[0]
        dp_1 = max(nums[1], nums[0])
        for i in range(2, n-1):
            dp_i = max(dp_1, nums[i] + dp_2)
            dp_2 = dp_1
            dp_1 = dp_i
        
        ans = dp_1
        
        dp_2 = nums[1]
        dp_1 = max(nums[2], nums[1])
        for i in range(3, n):
            dp_i = max(dp_1, nums[i] + dp_2)
            dp_2 = dp_1
            dp_1 = dp_i
        
        ans = max(ans, dp_1)
        return ans