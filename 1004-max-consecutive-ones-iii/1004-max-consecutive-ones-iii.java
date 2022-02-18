class Solution {
    public int longestOnes(int[] nums, int k) {
        int len = nums.length;
        if(k >= len)
            return len;
        
        int ans = 0, left = 0;
        int countZero = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 0)
                countZero++;
            while(countZero > k){
                if(nums[left] == 0)
                    countZero--;
                left++;
            }
            ans = Math.max(ans, i - left + 1);
        }
        return ans;
    }
}