class Solution {
public:
    int titleToNumber(string title) {
        int ans = 0;
        int len = title.length();
        unsigned int multiplier = 1;
        for(int i = len - 1; i >= 0; i--){
            int value = title[i] - 'A' + 1;
            ans += value * multiplier;
            multiplier *= 26;
        }
        return ans;
    }
};