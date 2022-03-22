class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int sum = 1 * n;
        
        for(int i = n-1; i >= 0; i--){
            int freq_a = i;
            int freq_z = n - i;
            int sum = freq_a * 1 + freq_z * 26;
            if(sum > k){
                int required = sum - k;
                ans[i] = 'z' - required;
                break;
            }
            ans[i] = 'z';
        }
        
        return ans;
    }
};