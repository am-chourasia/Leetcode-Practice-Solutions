class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if(n == 1)
            return 0;
        
        int allTraversed = (1 << n) - 1;
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        Set<Pair<Integer, Integer>> visited_pair = new HashSet<>();
        
        for(int i = 0; i < n; i++){
            Pair<Integer, Integer> p = new Pair(i, (1 << i));
            queue.add(p);
            visited_pair.add(p);
        }
        
        int level = 0;
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                Pair<Integer, Integer> p = queue.poll();
                int currentNode = p.getKey();
                int traversed = p.getValue();
                for(int neighbour : graph[currentNode]){
                    int newTraversed = traversed | (1 << neighbour);
                    if(newTraversed == allTraversed)
                        return level + 1;
                    Pair<Integer, Integer> k = new Pair<Integer, Integer>(neighbour, newTraversed);
                    if(!visited_pair.contains(k)){
                        visited_pair.add(k);
                        queue.add(k);                  
                    }
                }
            }
            level += 1;
        }
        
        return level;
    }
}