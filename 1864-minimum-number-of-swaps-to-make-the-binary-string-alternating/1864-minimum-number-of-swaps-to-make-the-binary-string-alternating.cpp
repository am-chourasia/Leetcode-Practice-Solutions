class Solution {
public:
    int minSwaps(string s) {
        int len = s.length();
        int zero = 0, one = 0;
        int mismatch1 = 0, mismatch2 = 0;
        
        int a = '0';
        for(int i = 0; i < len; i++){
            s[i] == '0' ? zero++ : one++;
            s[i] == a ? mismatch2 ++ : mismatch1 ++;
            a = (a == '0') ? '1' : '0';
        }
    
        if(len % 2 == 0){
            if(zero != one)
                return -1;
            return min(mismatch1 / 2, mismatch2 / 2);
        } else {
            if(zero + 1 == one)
                return mismatch2 / 2;
            else if(one + 1 == zero)
                return mismatch1 / 2;
            else
                return -1;
        }
    }
};