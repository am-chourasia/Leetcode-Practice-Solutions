class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long a = 0; a * a <= c; a++){
            long b = sqrt(c - a * a);
            if(b * b == (c - a * a))
                return true;
        }
        // Time Complexity:
            // sqrt(c)
            // 10 ^ 5
        
        return false;
    }
};