class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        
        ans.reserve(n);
        ans.push_back(to_string(nums[0]));
        
        for(int i = 1; i < n; i++){
            int prev = nums[i - 1];
            if(prev + 1 != nums[i])
                ans.push_back(to_string(nums[i]));
            else if(i == n-1 or nums[i] + 1 != nums[i + 1])
                ans.back() += "->" + to_string(nums[i]);
        }
        
        return ans;
    }
};