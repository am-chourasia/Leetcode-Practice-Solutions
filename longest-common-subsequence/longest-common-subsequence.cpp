class Solution {
    vector<vector<int>> dp;
    string s1;
    string s2;
public:
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        dp.resize(s1.size(), vector<int>(s2.size(), -1));
        return recur(0, 0);
    }
    int recur(int i, int j){
        if(i==s1.size() || j == s2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + recur(i+1, j+1);
        return dp[i][j] = max(recur(i+1, j), recur(i, j+1));
    }
};