class Solution {
    vector<int>* stones;
    vector<int> dp;
    int n;
    int calculate(int i){
        if(i >= n)
            return 0;
        if(dp[i] != INT_MAX)
            return dp[i];
        int ans = INT_MIN;
        ans = max(ans, stones->at(i) - calculate(i+1));
        if(i + 1 < n)
            ans = max(ans, stones->at(i) + stones->at(i+1) - calculate(i+2));
        if(i + 2 < n)
            ans = max(ans, stones->at(i) + stones->at(i+1) + stones->at(i+2) - calculate(i+3));
        return dp[i] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        stones = &stoneValue;
        dp.resize(n, INT_MAX);
        int ans = calculate(0);
        if(ans > 0)
            return "Alice";
        if(ans < 0)
            return "Bob";
        return "Tie";
    }
};