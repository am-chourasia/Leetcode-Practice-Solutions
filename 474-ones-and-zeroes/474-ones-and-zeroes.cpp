struct Tuple{
    int ones;
    int zeroes;
};
class Solution {
    unordered_map<int, Tuple> freq; // index against number of ones and zeroes they contain
    vector<vector<vector<int>>> dp;
    int select(vector<string>& strings, int idx, int m, int n){
        if(idx >= strings.size())
            return 0;
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
        
        int ones = freq[idx].ones;
        int zeroes = freq[idx].zeroes;
        
        int include = 0, exclude = 0;
        
        if(ones <= n and zeroes <= m)
            include = select(strings, idx + 1, m - zeroes, n - ones) + 1;
        exclude = select(strings, idx + 1, m, n);
        
        return dp[idx][m][n] = max(include, exclude);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        dp.resize(len, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        for(int i = 0; i < len; i++){
            string& s = strs[i];
            int zero = 0, one = 0;
            for(char c : s)
                (c == '1') ? one++ : zero++;
            freq[i] = {one, zero};
        }
        return select(strs, 0, m, n);
    }
};