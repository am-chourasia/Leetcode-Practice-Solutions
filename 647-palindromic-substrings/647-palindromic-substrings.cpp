class Solution {
    int isPalindrome(string& s, int start, int end){
        int n = end - start;
        for(int i = 0; i < n / 2; i++){
            if(s[start + i] != s[end - 1 - i])
                return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int start = 0; start < n; start++){
            for(int end = start + 1; end <= n; end++){
                if(isPalindrome(s, start, end))
                    count++;
            }
        }
        
        return count;
    }
};