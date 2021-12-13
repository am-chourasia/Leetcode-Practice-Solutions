class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        
        i, ans = 1, 0
        
        while i < n:
            count = 2
            d = nums[i-1] - nums[i] 
            i += 1
            while i<n and nums[i-1] - nums[i] == d:
                count += 1
                i += 1
            ans += (count * (count+1))//2 - count - count + 1
            
        return ans
                