class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int start = 0, end = people.length - 1;
        
        int boat_count = 0;
        
        while(start <= end){
            boat_count++;
            if(people[start] + people[end] <= limit)
                start++;
            end--;
        }
        
        return boat_count;
    }
}