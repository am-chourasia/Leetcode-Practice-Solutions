class Solution {
    public boolean canBeIncreasing(int[] nums) {
        int len = nums.length;
        int prev = nums[0];
        boolean already_removed = false; 
        
        for(int idx = 1; idx < len; idx++){
            if(nums[idx] <= prev){
                if(already_removed)
                    return false;
                
                boolean prev_removed = idx - 2 < 0 || nums[idx-2] < nums[idx];
                already_removed = true;
                if(prev_removed)
                    prev = nums[idx];
            } 
            else
                prev = nums[idx];
        }
        
        return true;
    }
}