class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        bool changed = false;
        
        for(int i = 1; i < len; i++){
            if(nums[i - 1] > nums[i]){
                if(changed)
                    return false;
                if(i - 2 < 0 or nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                changed = true;
            }
        }
        
        return true;
    }
};