class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        
        for(int t = 1; t <= n; t++){
            for(int i = 3; i >= 0; i--){
                dp[i] += dp[i + 1];
            }
        }
        
        return dp[0];
    }
};