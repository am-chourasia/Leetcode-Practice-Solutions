class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        if totalSum % 2 == 1:
            return False
        n = len(nums)
        target = totalSum // 2
        dp = {}
        
        def search(i, runningSum):
            if runningSum == target:
                return True
            if runningSum > target or i >= n:
                return False
            if (i, runningSum) in dp:
                return dp[i, runningSum]
            dp[i, runningSum] = search(i+1, runningSum) or search(i+1, runningSum + nums[i])
            return dp[i, runningSum]
        
        return search(0, 0)
        
#         dp = [[False for j in range(totalSum + 1)] for i in range(n+1)]
#         dp[0][0] = True
        
#         for i in range(1, n+1):
#             for j in range(1, totalSum + 1):
#                 if nums[i-1] <= j:
#                     dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
#                 else:
#                     dp[i][j] = dp[i-1][j]
        
#         return dp[n][totalSum]
        
        
        