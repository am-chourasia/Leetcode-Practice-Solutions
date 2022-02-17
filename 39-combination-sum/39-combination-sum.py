class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        output = []
        
        def backtrack(currentIndex, currentSum, currentCombination):
            if(currentSum == target):
                output.append(currentCombination)
                return
            for i in range(currentIndex, len(nums)):
                if currentSum + nums[i] <= target:
                    backtrack(i, currentSum + nums[i], currentCombination + [nums[i]])
                else:
                    return
        
        backtrack(0, 0, [])
        return output