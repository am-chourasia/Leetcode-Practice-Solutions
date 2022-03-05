class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        values = []
        n = len(nums)
        i = 0
        
        while i<n:
            j = i
            while j+1 < n and nums[j+1] == nums[j]:
                j += 1
            # when numbers are consecutive
            if len(values) == 0 or nums[j]-1 == nums[i-1]:
                values.append((j-i+1) * nums[i])
            # when numbers are non-consecutive, introduce a break with 0
            else:
                values.extend([0, (j-i+1) * nums[i]])
            i = j + 1
        
        
        dp =[0] * (len(values)+1)
        for index in range(1, len(values) + 1):
            dp[index] = max(dp[index-1], dp[index-2] + values[index-1])
        
        return dp[len(values)]