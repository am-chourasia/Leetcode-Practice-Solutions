class Solution {
    public boolean checkInclusion(String s1, String s2) {
        
        int len1 = s1.length(), len2 = s2.length();
       
        if (len1 > len2)
            return false;

        int[] chars = new int[26];
        for (Character c : s1.toCharArray())
            chars[c-'a']++;

        int start = 0, end = 0;
        int diff = len1;
        char temp;

        for (end = 0; end < len1; end++){
            temp = s2.charAt(end);
            chars[temp-'a']--;
            if (chars[temp-'a'] >= 0)
                diff--;
        }

        if (diff == 0)
            return true;

        while (end < s2.length()){
            temp = s2.charAt(start);
            if (chars[temp-'a'] >= 0)
                diff++;

            chars[temp-'a']++;
            start++;
 
            temp = s2.charAt(end);
            chars[temp-'a']--;
            if (chars[temp-'a'] >= 0)
                diff--;
 
            if (diff == 0)
                return true;
            
            end++;
        }
        
        return false;
    }
}