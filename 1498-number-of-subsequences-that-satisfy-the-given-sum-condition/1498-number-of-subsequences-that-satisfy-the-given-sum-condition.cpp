class Solution {
    int mod = 1e9 + 7;
    long long modpow(long long x, long long n, int m) {
        if (n == 0) 
            return 1;
        long long u = modpow(x,n/2,m);
        u = (u * u) % m;
        if (n%2 == 1) 
            u = (u*x)%m;
        return u;
    }
    // int modpow(int x, int n){
    //     if(n == 1)
    //         return x;
    //     int k = modpow(x, n/2);
    //     k = (k * k) % mod;
    //     if(n % 2 == 1)
    //         k = (k * x) % mod;
    //     return k;
    // }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] * 2 <= target){
                int search = target - nums[i];
                int mid = upper_bound(nums.begin() + i, nums.end(), search) - nums.begin();
                mid--;
                ans = (ans + modpow(2, mid - i, mod)) % mod;
            }
        }
        return ans;
    }
};