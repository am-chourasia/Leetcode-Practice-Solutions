class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int hashValue) {
        reverse(s.begin(), s.end());
        int n = s.length();
        vector<int> val(n);
        
        for(int i=0; i<n; i++)
            val[i] = s[i] - 'a' + 1;
        
        long long rolling = 0;
        long long mul = 1;
        
        for(int i = k-1; i >= 0; i--){
            rolling = (rolling + val[i] * mul) % mod;
            if(i != 0)
                mul = (mul * p) % mod;
        }
        
        int index = -1;
        if(rolling == hashValue)
            index = k-1;
        
        for(int i = 1, j = i+k-1; j < n; i++, j++){
            rolling = (rolling - (val[i-1]*mul) % mod + mod) % mod;
            rolling = (rolling * p) % mod;
            rolling = (rolling + val[j]) % mod;
            if(rolling == hashValue)
                index = j;
        }
        index = n - 1 - index;
        reverse(s.begin(), s.end());
        return s.substr(index, k);
    }
};