class Solution {
    public int smallestRepunitDivByK(int k) {
        if((k & 1) == 0) // if k is even, answer is not possible since the sequence is always odd
            return -1;
        
        // pegion hole principle:
        // to check the divisiblity of n,
        // we can always check the divisibilty of its remainder with k.
        // if any time remainder becomes zero, the answer is found
        // else if any remainder repeats, the answer is -1
        // We only need to run the loop atmost k times,
        // since the remainder must repeat after that
        
        int n = 0;
        for(int len = 1; len <= k; len++){
            n = n * 10 + 1;
            n = n % k;
            if(n == 0)
                return len;
        }
        return -1;
    }
}