class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int count = 0;
        int prev = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(prev != nums[i])
                count = 1;
            else 
                count++;
            prev = nums[i];

            if(count > 2){
                while(i < n and nums[i] == prev)
                    i++;
                if(i < n)
                    prev = nums[i];
                count = 1;
            }
            if(i < n)
                swap(nums[i], nums[k++]);
        }
        return k;
    }
};