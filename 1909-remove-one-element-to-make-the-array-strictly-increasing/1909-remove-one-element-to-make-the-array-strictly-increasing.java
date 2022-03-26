class Solution {
    public boolean canBeIncreasing(int[] nums) {
        int len = nums.length;
        int prev = nums[0];
        boolean already_removed = false; 
        
        for(int idx = 1; idx < len; idx++){
            if(nums[idx] <= prev){
                if(already_removed)
                    return false;
                if(idx + 1 == len)
                    break;
                
                boolean current_removed = prev < nums[idx + 1];
                boolean prev_removed = idx - 2 < 0 || nums[idx-2] < nums[idx];
                already_removed = true;
                
                if(current_removed)
                    prev = prev;
                else if(prev_removed)
                    prev = nums[idx];
                else
                    return false;
            } 
            else
                prev = nums[idx];
        }
        
        return true;
    }
}