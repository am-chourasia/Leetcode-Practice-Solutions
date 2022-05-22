class Solution {
    void checkPalindrome(string& s, int left, int right, int& count){
        while(left >= 0 and right < s.length() and s[left] == s[right])
            count++, left--, right++;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        
        for(int i = 0; i < n; i++){
            checkPalindrome(s, i, i, count);
            checkPalindrome(s, i, i + 1, count);
        }
        
        return count;
    }
};