class Solution {
    pair<int, int> findMini(vector<int>& nums, int val){
        int min1 = INT_MAX, min2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 3 == val){
                if(min1 > nums[i]){
                    min2 = min1;
                    min1 = nums[i];
                } else if(min2 > nums[i]){
                    min2 = nums[i];
                }
            }
        }
        
        return {min1, min2};
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; i++)
            sum += nums[i];
        
        if(sum % 3 == 0)
            return sum;
        
        pair<int, int> mini1 = findMini(nums, 1);
        pair<int, int> mini2 = findMini(nums, 2);
        
        int mini;
        if(sum % 3 == 1){
            mini = mini1.first;
            if(mini2.first != INT_MAX and mini2.second != INT_MAX)
                mini = min(mini, mini2.first + mini2.second);
        }
        else{
            mini = mini2.first;
            if(mini1.first != INT_MAX and mini1.second != INT_MAX)
                mini = min(mini, mini1.first + mini1.second);
        }
        
        if(mini == INT_MAX)
            return 0;
        
        return sum - mini;
    }
};