class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        
        ans = 0
        mod = 10 ** 9 + 7
        i, j = 0, n - 1
        
        while i <= j:
            while i <= j and nums[i] + nums[j] > target:
                j -= 1
            if i <= j and nums[i] + nums[j] <= target:
                ans += 1 << (j - i)
                ans %= mod
            i += 1
        
        return ans