class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        
        for i in range(len(nums)):
            while nums[i] - 1 != i and nums[nums[i] - 1] != nums[i]:
                temp = nums[i]
                nums[i] = nums[nums[i] - 1] 
                nums[temp - 1] = temp
        
        duplicates = []        
        for i in range(len(nums)):
            if nums[i] != i + 1:
                duplicates.append(nums[i])
            
        return duplicates