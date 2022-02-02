class Solution {
    bool check(vector<int>& pattern, vector<int>& roll){
        for(int i=0; i<26; i++)
            if(pattern[i] != roll[i])
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        
        if(m > n)
            return ans;
        vector<int> pattern(26);
        for(char& c : p)
            pattern[c-'a']++;
        
        vector<int> rolling(26);
        for(int i = 0; i < m; i++)
            rolling[s[i]-'a']++;
       
        for(int i = 0, j = m; j <= n; i++, j++){
            if(check(pattern, rolling))
                ans.push_back(i);
            rolling[s[i]-'a']--;
            if(j < n)
                rolling[s[j]-'a']++;
        }
        
        return ans;
    }
};