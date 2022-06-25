class Solution {
    public boolean checkPossibility(int[] nums) {
        int len = nums.length;
        if(len <= 2)
            return true;
        
        boolean modified = false;
        int prev = Integer.MIN_VALUE;
        int i = 0;
    
        while (i < len - 1) {
            int current = nums[i];
            int next = nums[i + 1];
            if(current >= prev && current > next){ // a peak is there.
                if(modified)
                    return false;                 // if the array has already been modified
                modified = true;
                if (prev <= next) {
                    // just ignore the current index;
                } else if (i + 2 == len || nums[i + 2] >= current) {
                    prev = current;
                    i = i + 1;
                } else {
                    return false;
                }
            }
            else {
                prev = current;
            }
            i = i + 1;
        }
        
        return true;
    }
}