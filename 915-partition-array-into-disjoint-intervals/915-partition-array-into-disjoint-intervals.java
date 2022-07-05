class Solution {
    public int partitionDisjoint(int[] nums) {
        int len = nums.length;
        int[] rightLowest = new int[len];
        rightLowest[len - 1] = nums[len - 1];
        
        for(int i = len - 2; i >= 0; i--)
            rightLowest[i] = Math.min(rightLowest[i + 1], nums[i + 1]);
        
        int leftMax = 0;
        for(int i = 0; i < len; i++){
            leftMax = Math.max(leftMax, nums[i]);
            int rightMin = rightLowest[i];
            if(leftMax <= rightMin)
                return i + 1;
        }
        
        return len;
    }
}