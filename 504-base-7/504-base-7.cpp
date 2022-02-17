class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool isNegative = num < 0;
        num = isNegative ? -num : num;
        string ans;
        while(num > 0){
            int rem = num % 7;
            num = num / 7;
            ans.push_back(rem + '0');
        }
        if(isNegative)
            ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};