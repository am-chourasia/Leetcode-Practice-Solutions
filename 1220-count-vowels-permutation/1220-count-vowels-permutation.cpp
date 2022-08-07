class Solution {
    int mod = 1'000'000'007;
    int calculatePermutation(map<char,vector<char>>& allowed, vector<vector<int>>& cache, char current, int index, int n){
        if(index == n - 1)
            return 1;
        
        if(cache[index][current - 'a'] != -1)
            return cache[index][current - 'a'];
        
        int ways = 0;
        for(char next : allowed[current])
            ways = (ways + calculatePermutation(allowed, cache, next, index + 1, n)) % mod;
        
        return cache[index][current - 'a'] = ways;
    }
public:
    int countVowelPermutation(int n) {
        map<char, vector<char>> allowed;
        allowed['a'] = {'e'};
        allowed['e'] = {'a', 'i'};
        allowed['i'] = {'a', 'e', 'o', 'u'};
        allowed['o'] = {'i', 'u'};
        allowed['u'] = {'a'};
        
        vector<vector<int>> cache(n, vector<int>(26, -1));
        int totalPermutation = 0;
        
        for(auto& [vowel, nextAllowed] : allowed)
            totalPermutation = (totalPermutation + calculatePermutation(allowed, cache, vowel, 0, n)) % mod;
        
        return totalPermutation;
    }
};