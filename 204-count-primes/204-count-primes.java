class Solution {
    public int countPrimes(int n) {
        if(n <= 2)
            return 0;
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        
        for(int i = 3; i*i < n; i += 2){
            if(isPrime[i] == true)
                for(int j = 2; j * i < n; j++)
                    isPrime[i * j] = false;
        }
        
        int count = 1;
        for(int i = 3; i < n; i+=2)
            if(isPrime[i])
                count++;
        
        return count;
    }
}