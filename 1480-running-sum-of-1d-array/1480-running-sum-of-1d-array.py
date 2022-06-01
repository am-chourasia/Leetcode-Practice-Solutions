class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0
        size = len(nums)
        ans = [0] * size
        
        for i in range(size):
            sum = sum + nums[i]
            ans[i] = sum
            
        return ans