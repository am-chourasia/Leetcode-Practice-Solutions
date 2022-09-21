class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        
        evenSum = sum(i for i in nums if i % 2 == 0)
        ans = []
        
        for val, index in queries:
            if nums[index] % 2 == 0:
                evenSum -= nums[index]
            nums[index] += val
            if nums[index] % 2 == 0:
                evenSum += nums[index]
            ans.append(evenSum)
        
        return ans