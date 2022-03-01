class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int highestPower = 1;
        for(int i = 1; i <= n; i++){
            if(((i - 1) & i) == 0){
                highestPower = i;
                ans[i] = 1;
            } else {
                ans[i] = 1 + ans[i - highestPower];
            }
        }
        
        return ans;
    }
};