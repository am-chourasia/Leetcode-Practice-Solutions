class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0], runningSum = nums[0];
        for(int i=1; i<nums.length; i++){
            runningSum = Math.max(nums[i], runningSum + nums[i]);
            sum = Math.max(sum, runningSum);
        }
        return sum;
    }
}