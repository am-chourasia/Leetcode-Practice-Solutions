class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        
        multiset<int> maximum;
        int left = 0, right = 0;
        for(right = 0; right < k; right++)
            maximum.insert(nums[right]);
        
        vector<int> slidingMax;
        int maxi = *maximum.rbegin();
        slidingMax.push_back(maxi);
        
        while(right < len){
            int add = nums[right];
            int remove = nums[left];
            maximum.erase(maximum.find(remove));
            maximum.insert(add);
            maxi = *maximum.rbegin();
            slidingMax.push_back(maxi);
            right++;
            left++;
        }
        
        return slidingMax;
    }
};