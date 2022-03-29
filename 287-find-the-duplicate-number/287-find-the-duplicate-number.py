class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        length = len(nums)
        for i in range(length):
            element = abs(nums[i])
            if nums[element] < 0:
                return element
            nums[element] = -nums[element]
        
        return -1