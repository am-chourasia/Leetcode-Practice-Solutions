class Solution {
public:
    int maxPower(string s) {
        int power = 1, maxPower = 1, c = s[0];
        for(int i=1; i < s.length(); i++){
            if(s[i] != c){
                maxPower = max(maxPower, power);
                power = 1, c = s[i];
            }
            else
                power++;
        }
        maxPower = max(maxPower, power);
        return maxPower;
    }
};