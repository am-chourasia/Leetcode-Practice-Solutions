class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int mod = 1e9 + 7;
        set<int> allNums(nums1.begin(), nums1.end());
        int len = nums2.size();
        long sum = 0;
        long gain = 0;

        for(int i = 0; i < len; i++){
            long originalDiff = abs(nums1[i] - nums2[i]);
            sum = sum + originalDiff;
            if(gain < originalDiff){
                auto nearest = allNums.lower_bound(nums2[i]);
                if(nearest != allNums.end()){
                    long newDiff = abs(nums2[i] - *nearest);
                    gain = max(gain, originalDiff - newDiff);
                }
                if(nearest != allNums.begin()){
                    long newDiff = abs(nums2[i] - *prev(nearest));
                    gain = max(gain, originalDiff - newDiff);
                }
            }
        }
        
        sum = (sum - gain) % mod;
        return sum;
    }
};