class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        if(len < k)
            return false;
        
        vector<bool> present(1 << k, false);
        int count = 0;
        int start = 0, end = k;
        int number = 0;
        int mul = 1 << (k - 1);
        
        while(start < end){
            int digit = s[start] - '0';
            number = number + mul * digit;
            mul >>= 1;
            start++;
        }
        
        present[number] = true;
        count++;
        start = 0, end = k, mul = 1 << (k - 1);
        
        while(end < len){
            int digRemoved = s[start] - '0';
            int digAdded = s[end] - '0';
            number -= digRemoved * mul;
            number <<= 1;
            number += digAdded;
            if(not present[number])
                present[number] = true, count++;
            start++, end++;
        }
        
        bool hasAll = count == (1 << k);
        return hasAll;
    }
};