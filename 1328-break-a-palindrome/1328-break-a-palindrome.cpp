class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1)
            return "";
        for (int idx = 0; idx < len / 2; idx ++) {
            if (palindrome[idx] != 'a') {
                palindrome[idx] = 'a';
                return std::move(palindrome);
            }
        }
        palindrome[len - 1] = 'b';
        return palindrome;
    }
};