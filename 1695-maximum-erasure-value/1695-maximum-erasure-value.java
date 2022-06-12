class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int len = nums.length;
        int left = 0, right = 0;
        int sum = 0;
        int maxSum = 0;
        var elements = new HashSet<Integer>();
        
        while(right < len){
            while(right < len && !elements.contains(nums[right])){
                sum += nums[right];
                elements.add(nums[right]);
                right += 1;
            }
            maxSum = Math.max(maxSum, sum);
            
            if(right < len){
                while(left < right && elements.contains(nums[right])){
                    sum -= nums[left];
                    elements.remove(nums[left]);
                    left += 1;
                }
            }
        }
        
        return maxSum;
    }
}