class Solution {
    public int findMaxLength(int[] nums) {
        int count = 0;
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1)
                count ++;
            else
                count --;
            if(map.containsKey(count)){
                int start = map.get(count);
                int end = i + 1;
                ans = Math.max(ans, end - start);
            }
            else
                map.put(count, i+1);
        }
        
        return ans;
    }
}