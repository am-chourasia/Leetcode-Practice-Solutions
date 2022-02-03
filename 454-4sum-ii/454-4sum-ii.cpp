class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums4.begin(), nums4.end());
        int len = nums1.size();
        int ans = 0;
        std::unordered_map<int, int> map1;
        
        for(int i=0; i < len; i++){
            for(int j = 0; j < len; j++){
                map1[nums1[i] + nums2[j]] ++;
            }
        }
        for(int i=0; i < len; i++){
            for(int j = 0; j < len; j++){
                int target = -(nums3[i] + nums4[j]);
                ans += map1[target];
            }
        }
        
        return ans;
    }
};