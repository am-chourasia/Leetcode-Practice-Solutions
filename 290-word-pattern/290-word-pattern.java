class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] ss = s.split(" ");   
        if(pattern.length() != ss.length)
            return false;
        
        HashMap<Character, String> map = new HashMap<>();
        HashMap<String, Character> string_map = new HashMap<>();
        
        for(int i = 0; i < ss.length; i++){
            char c = pattern.charAt(i);
            // if the pattern character or the string is seen before
            if(map.containsKey(c) || string_map.containsKey(ss[i])){
                // if the character does not corresponds to the string:
                if(!map.getOrDefault(c, "").equals(ss[i]))
                    return false;
                // if the string does not corresponds to the character:
                if(string_map.getOrDefault(ss[i], '#') != c)
                    return false;
            } else {
                // else put the character ans string into hashmap:
                map.put(c, ss[i]);
                string_map.put(ss[i], c);
            }
        }
        return true;
    }
}