class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return {nums};
        vector<int> permutation;
        permutation.reserve(n);
        recurse(nums, permutation, n - 1);
        return ans;
    }
    void recurse(vector<int>& nums, vector<int>& permutation, int idx){
        if(idx == 1){ // only two elements remain
            permutation.push_back(nums[1]);
            permutation.push_back(nums[0]);
            ans.push_back(permutation);
            swap(permutation[n - 1], permutation[n - 2]);
            ans.push_back(permutation);
            permutation.pop_back();
            permutation.pop_back();
            return;
        }
        
        for(int i = 0; i <= idx; i++){
            swap(nums[i], nums[idx]);
            permutation.push_back(nums[idx]);
            recurse(nums, permutation, idx - 1);
            permutation.pop_back();
            swap(nums[i], nums[idx]);
        }
    }
};