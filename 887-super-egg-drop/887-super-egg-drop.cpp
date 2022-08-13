class Solution {
    vector<vector<int>> dp;
    int stimulate(int floors, int eggs){
        if(floors == 0 || floors == 1)
            return floors;
        if(eggs == 1)
            return floors;
        if(dp[floors][eggs] != -1)
            return dp[floors][eggs];
        
        int minAttempts = INT_MAX;
        int up = floors, down = 1;
        while(up >= down){
            int mid = (down + up) / 2;
            int breaks = stimulate(mid - 1, eggs - 1);
            int notBreaks = stimulate(floors - mid, eggs);
            int moves = 1 + max(notBreaks, breaks);
            
            if(notBreaks < breaks){
                up = mid - 1;
            } else {
                down = mid + 1;
            }
            minAttempts = min(minAttempts, moves);
        }
        dp[floors][eggs] = minAttempts;
        return minAttempts;
    }
public:
    int superEggDrop(int eggs, int floors) {
        dp.resize(floors + 1, vector<int>(eggs + 1, -1));
        return stimulate(floors, eggs);
    }
};