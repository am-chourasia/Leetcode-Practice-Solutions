class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        for(int col = 0; col < n; col++){
            int i = 0;
            int j = col;
            while(j < n){
                if(j == i)
                    isPalindrome[i][j] = true;
                else if(j == i + 1)
                    isPalindrome[i][j] = s[i] == s[j];
                else{
                    if(s[i] == s[j] and isPalindrome[i + 1][j - 1])
                        isPalindrome[i][j] = true;
                }
                if(isPalindrome[i][j])
                    count++;
                j++;
                i++;
            }
        }
        
        return count;
    }
};