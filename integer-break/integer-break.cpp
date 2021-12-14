class Solution {
public:
    int integerBreak(int n) {
        if(n <= 2)
            return 1;
        if(n == 3)
            return 2;
        
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4;
        
        for(int i = 5; i<=n; i++){
            int a = 1, b = i-a;
            // a + b = i
            // maximizing a * b:
            while(a <= b){
                dp[i] = max(dp[i], dp[a] * dp[b]);
                a++, b--;
            }
        }
        
        return dp[n];
    }
};