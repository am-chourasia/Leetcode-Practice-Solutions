class Solution:
    def search(self, nums: List[int], target: int) -> int:
        size = len(nums)
        start = -1
        end = size - 1
        while start + 1 < end:
            mid = (start + end) // 2
            if nums[mid] > nums[end]:
                start = mid
            else:
                end = mid
        
        pivot = end
        start = pivot
        end = pivot + size
        while start < end:
            mid = (start + end) // 2
            rmid = mid % size # rotated mid
            # print(start, end, rmid)
            if nums[rmid] == target:
                return rmid
            if nums[rmid] > target:
                end = mid
            else:
                start = mid + 1
                
        return -1
                