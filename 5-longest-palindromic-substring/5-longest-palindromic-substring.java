class Solution {
    int starting = 0;
    int longest = 0;
    void findLongest(int left, int right, String s){
        int len = s.length();
        while(left >= 0 && right < len && s.charAt(left) == s.charAt(right)){
            int length = right - left + 1;
            if(longest < length){
                starting = left;
                longest = length;
            }
            left--; right++;
        }
    }
    public String longestPalindrome(String s) {
        int len = s.length();
        for(int i = 0; i < len; i++){
            findLongest(i, i, s);
            findLongest(i, i + 1, s);
        }
        return s.substring(starting, starting + longest);
    }
}