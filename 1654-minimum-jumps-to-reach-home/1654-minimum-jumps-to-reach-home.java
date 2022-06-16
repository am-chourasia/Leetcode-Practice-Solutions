class Solution {
    public int minimumJumps(int[] forbidden, int forward, int backward, int home) {
        int last = forward + backward + home;
        
        Queue<Pair<Integer, Integer>> queue = new LinkedList();
        // node, direction it has been discovered from
        queue.offer(new Pair(0, 0));
        
        Set<Pair<Integer, Integer>> seen = new HashSet<>(queue);
        for (int pos : forbidden) {
            seen.add(new Pair(0, pos));
            seen.add(new Pair(1, pos));
            last = Math.max(last, pos + forward + backward);
        }
        
        int distance = 0;
        
        while(!queue.isEmpty()){
            for(int __ = queue.size(); __ > 0; --__){
                Pair<Integer, Integer> pair = queue.poll();
                int direction = pair.getKey();
                int node = pair.getValue();
                if(node == home)
                    return distance;
                
                int forwarded = node + forward;
                int backwarded = node - backward;
                var forwardNode = new Pair<Integer, Integer>(0, forwarded);
                var backwardNode = new Pair<Integer, Integer>(1, backwarded);
                
                if(forwarded <= last && seen.add(forwardNode))
                    queue.offer(forwardNode);
                if(direction == 0 && backwarded >= 0 && seen.add(backwardNode))
                    queue.offer(backwardNode);
            }
            distance += 1;
        }
        
        return -1;
    }
}