class Solution {
public:
    int findComplement(int num) {
        int msb = log2(num);
        int mask = (1<<msb) - 1;
        num = (~num) & mask;
        return num;
    }
};