class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        count = 0
        
        if k == 0:
            freq = {}
            for n in nums:
                freq[n] = freq.get(n, 0) + 1
            for num, frequency in freq.items():
                if frequency > 1:
                    count += 1
            return count
            
        nums = set(nums)
        for i in nums:
            if i + k in nums:
                count += 1
            if i - k in nums:
                count += 1
        
        return count // 2