class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int mid = len / 2;
        
        int target = nums[mid];
        int moves = 0;
        for(int i = 0; i < len; i++)
            moves += abs(target - nums[i]);
        return moves;
    }
};