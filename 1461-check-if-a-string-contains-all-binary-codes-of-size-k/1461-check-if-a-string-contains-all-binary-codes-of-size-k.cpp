class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        if(len < k)
            return false;
        
        vector<bool> present(1 << k, false);
        int need = 1 << k;
        int oneHash = need - 1;
        int start = 0, end = k;
        int number = 0;
        
        while(start < end){
            int digit = s[start] - '0';
            number  = ((number << 1) & oneHash) | digit;
            start++;
        }
        
        present[number] = true;
        need--;
        start = 0;
        
        while(end < len){
            int digit = s[end] - '0';
            number  = ((number << 1) & oneHash) | digit;
            if(not present[number])
                present[number] = true, need--;
            start++, end++;
        }
        
        bool hasAll = need == 0;
        return hasAll;
    }
};