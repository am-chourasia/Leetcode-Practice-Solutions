class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        length = len(nums)
        
        def partition(index, end):
            left = index + 1
            right = end - 1
            while left <= right:
                if nums[right] >= nums[index]:
                    nums[right], nums[left] = nums[left], nums[right]
                    left += 1
                else:
                    right -= 1
            nums[index], nums[right] = nums[right], nums[index]
            return right
        
        
        start = 0
        end = length
        k = k - 1
        while True:
            index = partition(start, end)
            if index == k:
                return nums[index]
            if index > k:
                end = index
            else:
                start = index + 1
            
        return 0