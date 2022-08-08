class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        length = len(nums)
        longestSeq = []
        for i in range(length):
            if i == 0 or longestSeq[-1] < nums[i]:
                longestSeq.append(nums[i]);
            else:
                index = bisect.bisect_left(longestSeq, nums[i]);
                longestSeq[index] = nums[i]
        
        return len(longestSeq)