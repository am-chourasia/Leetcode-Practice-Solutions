class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        int start = 0, end = len;
        
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        
        return -1;
    }
}