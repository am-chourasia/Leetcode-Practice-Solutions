class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int count = 0;
        int prev = INT_MIN;
        int n = nums.size();
        int i = 0;
        
        while(i < n){
            if(nums[i] >= prev){
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
                cout << i << " " << k << endl;
                if(i < n)
                    swap(nums[i], nums[k++]);
            }
            i++;
        }
        return k;
    }
};