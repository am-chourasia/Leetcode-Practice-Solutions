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
                j++;
                i++;
            }
        }
        
        for(int start = 0; start < n; start++){
            for(int end = start; end < n; end++){
                if(isPalindrome[start][end])
                    count++;
            }
        }
        
        return count;
    }
};