class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] represents the number of ways to get 'i' as sum
        vector<unsigned long long> dp(target+1, 0ll);
        // there is one way to get sum = 0: by choosing nothing
        dp[0] = 1;
        
        for(long long i=0; i<=target; i++){
            for(auto x: nums){
                if(i+x <= target)
                    dp[i+x] += dp[i];
            }
        }
                
        return dp[target];
    }
};