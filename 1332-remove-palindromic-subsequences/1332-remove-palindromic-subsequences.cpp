class Solution {
    bool isPalindrome(string& s){
        int len = s.length();
        for(int i = 0; i < len/2 ; i++){
            if(s[i] != s[len - 1 - i])
                return false;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
            return 1;
        return 2;
    }
};