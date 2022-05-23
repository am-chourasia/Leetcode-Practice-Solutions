class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < len; i++){
            string& s = strs[i];
            int zero = 0, one = 0;
            for(char c : s)
                (c == '1') ? one++ : zero++;
            
            for(int i = m; i >= zero; i--){
                for(int j = n; j >= one; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);                    
                }
            }
        }
        return dp[m][n];
    }
};