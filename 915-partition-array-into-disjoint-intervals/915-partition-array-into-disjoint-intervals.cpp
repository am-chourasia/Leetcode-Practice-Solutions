class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int> rightLowest(len);
        rightLowest[len - 1] = nums.back();
        
        for(int i = len - 2; i >= 0; i--)
            rightLowest[i] = min(rightLowest[i + 1], nums[i + 1]);
        
        int leftMax = 0;
        for(int i = 0; i < len; i++){
            leftMax = max(leftMax, nums[i]);
            int rightMin = rightLowest[i];
            if(leftMax <= rightMin)
                return i + 1;
        }
        
        return len;
    }
};