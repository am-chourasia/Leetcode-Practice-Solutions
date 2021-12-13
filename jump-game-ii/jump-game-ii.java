class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int current = n-1, count = 0;
        while(current != 0){
            for(int furthestAccesible = 0; furthestAccesible < current; furthestAccesible++){
                if(nums[furthestAccesible] + furthestAccesible >= current){
                    count++;
                    current = furthestAccesible;
                    break;
                }
            }
        }
        return count;
    }
}