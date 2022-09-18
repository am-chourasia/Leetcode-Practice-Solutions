class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int len1 = nums.size();
        int len2 = multipliers.size();
        vector<vector<int>> dp(len2 + 1, vector<int>(len2 + 1, 0)); 
        
        for (int index = len2 - 1; index >= 0; index--) {
            for (int start = index; start >= 0; start--) {
                int end = len1 - 1 - (index - start);
                // cout << start << " " << end << endl;
                int left = multipliers[index] * nums[start] + dp[start + 1][index + 1];
                int right = multipliers[index] * nums[end] + dp[start][index + 1];
                dp[start][index] = max(left, right);
            }
        }
        
        return dp[0][0];
    }
};