class Solution {
    public int minimumDeviation(int[] nums) {
        int n = nums.length;
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // maxHeap
        
        int currentMin = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0)
                pq.add(nums[i]);
            else{
                nums[i] = nums[i] * 2;
                pq.add(nums[i]);
            }
            currentMin = Math.min(currentMin, nums[i]);
        }
        
        int ans = Integer.MAX_VALUE;
        while(true){
            int maximum = pq.poll();
            ans = Math.min(ans, maximum - currentMin);
            if(maximum % 2 == 1)
                break;
            else
                pq.add(maximum/2);
            currentMin = Math.min(currentMin, maximum/2);
        }
        
        return ans;
    }
}