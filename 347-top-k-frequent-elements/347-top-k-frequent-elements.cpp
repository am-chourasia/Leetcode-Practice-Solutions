class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums)
            freq[i]++;
        vector<pair<int, int>> vi;
        vi.reserve(freq.size());
        
        for(auto m : freq)
            vi.push_back(m);
        
        partial_sort(vi.begin(), vi.begin() + k,vi.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = vi[i].first;
        
        return ans;
    }
};