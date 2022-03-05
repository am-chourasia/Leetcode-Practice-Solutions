class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int, int>> A(n); // naya, purana
        
        for(int i = 0; i < n; i++){
            string purana = to_string(nums[i]);
            int size = purana.size();
            string naya(size, '0');
            for(int i = 0; i < size; i++)
                naya[i] = mapping[purana[i] - '0'] + '0';
            int k = stoi(naya);
            A[i] = {k, nums[i]};
        }
        
        sort(A.begin(), A.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2){
            if(p1.first != p2.first)
                return p1.first < p2.first;
            return false;
        });
        
        vector<int> ans(n);
        int i = 0;
        for(auto &p : A)
            ans[i++] = p.second;
        
        return ans;
    }
};