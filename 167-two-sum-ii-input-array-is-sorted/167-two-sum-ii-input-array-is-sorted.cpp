class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int p1 = 0, p2 = len - 1;
        while(p1 < p2){
            int sum = nums[p1] + nums[p2];
            if(sum == target)
                break;
            if(sum < target)
                p1++;
            else
                p2--;
        }
        return {p1 + 1, p2 + 1};
    }
};