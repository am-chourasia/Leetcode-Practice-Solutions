class Solution {
public:
    bool validPalindrome(string s) {
        int idx = -1;
        int len = s.length();
        
        for(int left = 0; left < len / 2; left++){
            int right = len - 1 - left;
            if(s[left] != s[right]){
                idx = left;
                break;
            }
        }
        if(idx == -1)
            return true;
        bool leftDelete = isPalindrome(s, idx + 1, len - 1 - idx);
        if(leftDelete)
            return true;
        bool rightDelete = isPalindrome(s, idx, len - 1 - idx - 1);
        return rightDelete;
    }
    bool isPalindrome(string& s, int left, int right){
        while(left <= right)
            if(s[left++] != s[right--])
                return false;
        return true;
    }
};