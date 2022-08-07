class Solution {
    public String longestPrefix(String s) {
        int len = s.length();
        
        int[] lps = new int[len + 1];
        lps[0] = 0;
        int i = 1, j = 0;
        while(i < len){
            if(s.charAt(i) == s.charAt(j))
                lps[++i] = ++j;
            else {
                if(j == 0)
                    i += 1;
                j = lps[j];
            }
        }
        
        StringBuilder ans = new StringBuilder(lps[len - 1]);
        for(i = len - lps[len]; i < len; i++)
            ans.append(s.charAt(i));
        
        return ans.toString();
    }
}