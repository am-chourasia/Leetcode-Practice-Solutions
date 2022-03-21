class Solution {
    public int minSwaps(String s) {
        int len = s.length();
        int mismatch = 0;
        
        for(int i = 0; i < len; i++){
            char element = s.charAt(i);
            if(element == '[')
                mismatch++;
            else if(mismatch > 0)
                mismatch--;
        }
        
        return (mismatch + 1) / 2;
    }
}