class Solution {
    public int twoCitySchedCost(int[][] costs) {
        var city1 = new PriorityQueue<Integer>();
        var city2 = new PriorityQueue<Integer>();
        
        int people = costs.length;
        int total_cost = 0;
        
        for(int i = 0; i < people; i++){
            int city1_cost = costs[i][0];
            int city2_cost = costs[i][1];
            int diff = city1_cost - city2_cost;
            if(diff == 0){
                total_cost += city1_cost;
            }
            else if(diff > 0){ // cost of city 1 is more
                total_cost += city2_cost;
                city2.add(diff);
            }
            else{ // cost of city 2 is more;
                total_cost += city1_cost;
                city1.add(-diff);
            }
        }
        
        while(city1.size() > people / 2)
            total_cost += city1.poll();
        while(city2.size() > people / 2)
            total_cost += city2.poll();
        
        return total_cost;
    }
}