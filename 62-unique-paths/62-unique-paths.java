class Solution {
    public int uniquePaths(int m, int n) {
        // nCr
        int total_choices = (m - 1) + (n - 1);
        int maxi = Math.max(n - 1, m - 1);
        
        long numerator = total_choices;
        long denominator = 1;
        long result = 1;
        
        while(numerator > maxi){
            if(numerator % denominator == 0){
                result = result * (numerator / denominator);
            } else {
                result = result * numerator;
                result = result / denominator;
            }
            numerator--;
            denominator++;
        }
        
        return (int)result;
    }
}