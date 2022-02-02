class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        ArrayList<Integer> soln = new ArrayList<Integer>();
        int len = p.length(), slen = s.length();
       
        if (slen < len)
            return soln;

        int[] chars = new int[26];
        for (Character c : p.toCharArray())
            chars[c-'a']++;

        int start = 0, end = 0;
        int diff = len;
        char temp;

        for (end = 0; end < len; end++){
            temp = s.charAt(end);
            chars[temp-'a']--;
            if (chars[temp-'a'] >= 0)
                diff--;
        }

        if (diff == 0)
            soln.add(0);
 
        while (end < s.length()){
            temp = s.charAt(start);
            if (chars[temp-'a'] >= 0)
                diff++;

            chars[temp-'a']++;
            start++;
 
            temp = s.charAt(end);
            chars[temp-'a']--;
            if (chars[temp-'a'] >= 0)
                diff--;
 
            if (diff == 0)
                soln.add(start);
            
            end++;
        }
        
        return soln;
    }
}