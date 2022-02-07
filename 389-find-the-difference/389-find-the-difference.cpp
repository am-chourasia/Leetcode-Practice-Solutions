class Solution {
public:
    char findTheDifference(string s, string t) {
        char xored = 0;
        for(char c : s)
            xored = xored ^ c;
        for(char c : t)
            xored = xored ^ c;
        return xored;
    }
};