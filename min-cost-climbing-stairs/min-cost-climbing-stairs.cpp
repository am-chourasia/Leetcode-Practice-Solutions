class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp0 = cost[0];
        int dp1 = cost[1];
        int temp;
        
        for(int i=2; i<n; i++){
            temp = cost[i] + min(dp0, dp1);
            dp0 = dp1;
            dp1 = temp;
        }
        
        return min(dp0, dp1);
    }
};