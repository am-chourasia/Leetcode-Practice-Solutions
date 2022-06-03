class Solution {
    bool isPalindrome(string& s){
        int n = s.length();
        for(int i = 0; i < n / 2; i++)
            if(s[i] != s[n - 1 - i])
                return false;
        return true;
    }
public:
    int maxProduct(string s) {
        vector<pair<int, int>> substrings; // length, indexes;
        int len = s.length();
        
        for(int mask = 1; mask <= (1 << len); mask++){
            string substring;
            for(int i = 0; i < len; i++)
                if(mask & (1 << i))
                    substring.push_back(s[i]);
            if(isPalindrome(substring))
                substrings.push_back({substring.length(), mask});
        }
        
        int n = substrings.size();
        int ans = 1;
        
        for(int i = 0; i < n; i++){
            int mask1 = substrings[i].second;
            for(int j = i + 1; j < n; j++){
                int mask2 = substrings[j].second;
                if((mask1 & mask2) == 0){
                    int product = substrings[i].first * substrings[j].first;
                    ans = max(ans, product);
                }
            }
        }
        
        return ans;
    }
};