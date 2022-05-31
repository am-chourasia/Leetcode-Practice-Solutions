class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        if(len < k)
            return false;
        
        unordered_set<int> present;
        int start = 0, end = k;
        int number = 0;
        int mul = 1 << (k - 1);
        
        while(start < end){
            int digit = s[start] - '0';
            number = number + mul * digit;
            mul >>= 1;
            start++;
        }
        
        present.insert(number);
        start = 0, end = k, mul = 1 << (k - 1);
        
        while(end < len){
            int digRemoved = s[start] - '0';
            int digAdded = s[end] - '0';
            number -= digRemoved * mul;
            number <<= 1;
            number += digAdded;
            present.insert(number);
            start++, end++;
        }
        
        bool hasAll = present.size() == (1 << k);
        return hasAll;
    }
};