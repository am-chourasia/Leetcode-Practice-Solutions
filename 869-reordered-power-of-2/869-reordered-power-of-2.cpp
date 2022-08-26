class Solution {
    bool isPowerOf2 (string& num) {
        int n = stoi(num);
        if (n != 0 and (n & (n - 1)) == 0)
            return true;
        return false;
    }
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        do {
            if (num[0] != '0' and isPowerOf2(num))  
                return true;
        } while ( next_permutation(num.begin(), num.end()) );
        
        return false;
    }
};