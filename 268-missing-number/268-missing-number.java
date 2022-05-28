class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        
        for(int i = 0; i < n; i++){
            int index = nums[i] % 100000;
            if(index < n)
                nums[index] = 100000 + nums[index];
        }
        
        for(int i = 0; i < n; i++)
            if(nums[i] < 100000)
                return i;
        
        return n;
    }
}