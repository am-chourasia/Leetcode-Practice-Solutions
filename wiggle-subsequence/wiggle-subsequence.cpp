class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pos = 1, neg = 1;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1])
                pos = neg + 1;
            else if(nums[i] < nums[i-1])
                neg = pos + 1;
        }
        return max(neg, pos);
    }
};