class Solution:
    def check(self, nums: List[int]) -> bool:
        # only one drop is allowed:
        dropped = False
        
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                if not dropped:
                    dropped = True
                else:
                    return False
        
        if dropped:
            return nums[0] >= nums[-1]
        return True
        