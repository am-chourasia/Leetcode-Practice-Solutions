class Solution {
    public int findDuplicate(int[] nums) {
        int size = nums.length;
        for(int i = 0; i < size; i++){
            int element = Math.abs(nums[i]);
            if(nums[element] < 0)
                return element;
            nums[element] = -nums[element];
        }
        return -1;
    }
}