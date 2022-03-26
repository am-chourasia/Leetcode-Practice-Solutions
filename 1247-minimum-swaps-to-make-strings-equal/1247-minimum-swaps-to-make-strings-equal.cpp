class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
            return -1;
        
        int xy = 0;
        int yx = 0;
        for(int i = 0; i < len1; i++){
            if(s1[i] == 'x' and s2[i] == 'y')
                xy++;
            else if(s1[i] == 'y' and s2[i] == 'x')
                yx++;
        }
        
        if((xy + yx) % 2 == 1)
            return -1;
        
        int swaps = xy / 2 + yx / 2 + 2 * (xy % 2);
        return swaps;
    }
};