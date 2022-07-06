class Solution {
    public int trailingZeroes(int n) {
        int trailingZeroes = 0;
        while(n > 0){
            trailingZeroes += n / 5;
            n = n / 5;
        }
        return trailingZeroes;
    }
}