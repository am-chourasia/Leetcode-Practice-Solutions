class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length();
        if(len < k)
            return false;
        
        vector<bool> present(1 << k, false);
        int need = 1 << k;
        int oneHash = need - 1;
        int number = 0;
        
        for(int end = 0; end < len; end++){
            int digit = s[end] - '0';
            number  = ((number << 1) & oneHash) | digit;
            if(end >= k - 1 and not present[number])
                present[number] = true, need--;
        }
        
        bool hasAll = need == 0;
        return hasAll;
    }
};