class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def partition(left, right):
            pivot, l, r = nums[left], left + 1, right
            while l <= r:
                if nums[l] < pivot and nums[r] > pivot:
                    nums[r], nums[l] = nums[l], nums[r]
                    r -= 1
                    l += 1
                if nums[l] >= pivot:
                    l += 1
                if nums[r] <= pivot:
                    r -= 1
            nums[left], nums[r] = nums[r], nums[left]
            return r
        
        left, right = 0, len(nums) - 1
        while left <= right:
            idx = partition(left, right)
            if idx == k - 1:
                return nums[idx]
            elif idx < k - 1:
                left = idx + 1
            else:
                right = idx - 1
        
        return nums[right]