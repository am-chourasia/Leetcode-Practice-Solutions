class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for(int i = 0; i < n; i++)
            sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end(), greater<pair<int, int>>());
        sort(sorted.begin(), sorted.begin() + k, [](pair<int,int>& a, pair<int,int>& b){
            if(a.second < b.second)
                return true;
            return false;
        });
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = sorted[i].first;
        return ans;
    }
};