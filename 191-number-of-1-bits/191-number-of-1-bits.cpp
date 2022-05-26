class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0; i <= 31; i++){
            uint32_t k = 1u << i;
            if(n & k)
                count++;
        }
        
        return count;
    }
};