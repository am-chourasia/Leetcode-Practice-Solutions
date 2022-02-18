class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= n)
            return n;
        vector<int> prefix(n + 1);
        vector<int> suffix(n + 1);
        for(int i = 1; i <= n; i++){
            if(nums[i-1] == 0)
                prefix[i] = 0;
            else
                prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == 0)
                suffix[i] = 0;
            else
                suffix[i] = suffix[i + 1] + nums[i];
        }
        
        int p1 = 0, p2 = 0;
        int count = 0;
        while(p1 < n and nums[p1] == 1)
            p1++;
        if(p1 == n)
            return n;
        p2 = p1;
        while(p2 < n){
            if(nums[p2] == 0)
                count++;
            if(count >= k)
                break;
            p2++;
        }
        if(p2 == n)
            return n;
        int ans = 0;
        while(p2 < n){
            int t = prefix[p1] + suffix[p2 + 1] + (p2 - p1 + 1);
            if(k == 0)
                t = max(prefix[p1], suffix[p2+1]);
            ans = max(ans, t);
            p1++, p2++;
            while(p1 < n and nums[p1] == 1)
                p1++;
            while(p2 < n and nums[p2] == 1)
                p2++;
        }
        
        return ans;
    }
};