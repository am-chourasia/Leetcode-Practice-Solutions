class Solution {
    int s_length;
    int p_length;
    vector<vector<int>> dp;
    bool check(string& s, string& p, int i, int j){
        if(j == p_length)
            return i == s_length;
        if(i == s_length){
            while(j < p_length){
                if(p[j] != '*')
                    return false;
                j += 1;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j] == '?'){
            return dp[i][j] = check(s, p, i + 1, j + 1);
        }
        else if(p[j] == '*'){
            bool included = check(s, p, i + 1, j + 1);
            if(included)
                return dp[i][j] = true;
            bool notIncluded = check(s, p, i + 1, j);
            if(notIncluded)
                return dp[i][j] = true;
            bool nothing = check(s, p, i, j + 1);
            if(nothing)
                return dp[i][j] = true;
        }
        else if(s[i] == p[j]){
            return dp[i][j] = check(s, p, i + 1, j + 1);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        s_length = s.length();
        p_length = p.length();
        dp.resize(s_length + 1, vector<int>(p_length + 1, -1));
        return check(s, p, 0, 0);
    }
};