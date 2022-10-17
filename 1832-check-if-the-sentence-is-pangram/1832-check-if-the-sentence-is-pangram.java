class Solution {
    public boolean checkIfPangram(String sentence) {
        int marker = 0;
        int length = sentence.length();
        for (int i = 0; i < length; i++) {
            int idx = sentence.charAt(i) - 'a';
            marker = marker | (1 << idx);
        }
        
        if (marker == ((1 << 26) - 1))
            return true;
        return false;
    }
}