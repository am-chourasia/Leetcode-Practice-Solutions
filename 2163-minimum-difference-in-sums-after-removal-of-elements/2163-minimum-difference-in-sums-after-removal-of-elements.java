class Solution {
    public long minimumDifference(int[] nums) {
        int len = nums.length;
        int n = len / 3;
        long prefix[] = new long[n + 1];
        long suffix[] = new long[n + 1];
        Queue<Integer> pq = new PriorityQueue<>(n, Collections.reverseOrder());
        
        long sum = 0;
        for(int i = 0; i < n; i++){
            pq.add(nums[i]);
            sum += nums[i];
        }
        
        prefix[0] = sum;
        int k = 1;
        for(int i = n; i < 2 * n; i++){
            if(nums[i] < pq.peek()){
                sum -= pq.peek();
                pq.poll();
                pq.offer(nums[i]);
                sum += nums[i];
            }
            prefix[k++] = sum;
        }
        
        pq = new PriorityQueue<Integer>();
        sum = 0;
        for(int i = len - 1; i >= 2 * n; i--){
            pq.add(nums[i]);
            sum += nums[i];
        }
        
        suffix[n] = sum;
        k = n-1;
        for(int i = 2 * n - 1; i >= n; i--){
            if(nums[i] > pq.peek()){
                sum -= pq.peek();
                pq.poll();
                pq.offer(nums[i]);
                sum += nums[i];
            }
            suffix[k--] = sum;
        }
        
        long ans = Long.MAX_VALUE;
        for(int i = 0; i <= n; i++)
            ans = Math.min(ans, prefix[i] - suffix[i]);
        
        return ans;
    }
}