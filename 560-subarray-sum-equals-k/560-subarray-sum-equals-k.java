class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int runningSum = 0;
        int count = 0;
        map.put(0, 1);
        
        for(int i = 0; i < nums.length; i++){
            runningSum += nums[i];
            count += map.getOrDefault(runningSum - k, 0);
            map.put(runningSum, map.getOrDefault(runningSum, 0) + 1);
        }
        
        return count;
    }
}