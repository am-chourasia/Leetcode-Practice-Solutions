class Solution {
public:
    char findTheDifference(string s, string t) {
        char xored = 0;
        for(int i = 0; i < s.length(); i++)
            xored = xored ^ s[i];
        for(int i = 0; i < t.length(); i++)
            xored = xored ^ t[i];
        return xored;
    }
};