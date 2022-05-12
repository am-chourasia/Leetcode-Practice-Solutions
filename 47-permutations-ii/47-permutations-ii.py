class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        output = []
        
        def backtrack(currentPermutation):
            if len(nums) == len(currentPermutation):
                output.append(currentPermutation)
                return
            
            for num in freq:
                if freq[num] > 0:
                    freq[num] -= 1
                    backtrack(currentPermutation + [num])
                    freq[num] += 1
        
        backtrack([])
        return output
        