class Solution {
    boolean isSet(int n, int i){
        if((n & (1 << i)) != 0)
            return true;
        return false;
    }
    public int findDuplicate(int[] nums) {
        int n = nums.length - 1;
        int duplicate = 0;
        
        for(int i = 0; i < 31; i++){
            int bit_count = 0;
            int nums_count = 0;
            int mask = (1 << i);
            
            for(int idx = 0; idx <= n; idx++){
                if(isSet(idx, i))
                    bit_count++;
                if(isSet(nums[idx], i))
                    nums_count++;
            }
            
            if(nums_count - bit_count > 0)
                duplicate |= mask;
        }
        
        return duplicate;
    }
}