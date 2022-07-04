class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        int[] cache = new int[len];
        
        cache[0] = 1;
        for(int i = 1; i < len; i++){
            cache[i] = 1;
            if(ratings[i] > ratings[i - 1])
                cache[i] += cache[i - 1];
        }
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && cache[i] <= cache[i + 1])
                cache[i] = cache[i + 1] + 1;
        }
        
        int minCandy = IntStream.of(cache).sum();
        return minCandy;
    }
}