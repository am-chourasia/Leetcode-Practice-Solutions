class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        if(len == 1 or k >= len)
            return len;
        
        int ans = 0;
        for(char alpha = 'A'; alpha <= 'Z'; alpha++){
            int countAlterChar = 0;
            int left = 0;
            for(int i = 0; i < len; i++){
                if(s[i] != alpha)
                    countAlterChar++;
                while(countAlterChar > k){
                    if(s[left] != alpha)
                        countAlterChar--;
                    left++;
                }
                ans = max(ans, i - left + 1);
            }
        }
        return ans;
    }
};