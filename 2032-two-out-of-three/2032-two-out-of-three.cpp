class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> presence; 
        // value : bit 0 -> present in nums1 and so on 
        
        for(int element : nums1)
            presence[element] = presence[element] | 1;
        for(int element : nums2)
            presence[element] = presence[element] | 2;
        for(int element : nums3)
            presence[element] = presence[element] | 4;
        
        vector<int> ans;
        for(const auto& [element, appearance] : presence){
            if(appearance != 1 and appearance != 2 and appearance != 4)
                ans.push_back(element);
        }
        
        return ans;
    }
};