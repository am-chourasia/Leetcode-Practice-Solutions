class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        if(len == 0)
            return new int[]{-1, -1};
        
        int begin = -1, end = len - 1;
        while(begin + 1 < end){
            int mid = (begin + end) / 2;
            if(nums[mid] >= target)
                end = mid;
            else
                begin = mid;
        }
        if(nums[end] != target)
            return new int[]{-1, -1};
        
        int firstOccurence = end;
        begin = firstOccurence; 
        end = len;
        
        while(begin + 1 < end){
            int mid = (begin + end) / 2;
            if(nums[mid] <= target)
                begin = mid;
            else
                end = mid;
        }
        int lastOccurence = begin;
        
        return new int[]{firstOccurence, lastOccurence};
    }
}