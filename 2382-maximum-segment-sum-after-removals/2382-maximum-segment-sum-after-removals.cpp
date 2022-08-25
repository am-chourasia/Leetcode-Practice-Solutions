class DSU {
public:
    vector<long long> parent;
    DSU(int size) {
        parent.resize(size, INT_MAX);
    }
    int find(int idx) {
        if (parent[idx] < 0)
            return idx;
        parent[idx] = find(parent[idx]);
        return parent[idx];
    }
    void merge(int idx1, int idx2) {
        int parent1 = find(idx1);
        int parent2 = find(idx2);
        parent[parent1] += parent[parent2];
        parent[parent2] = parent1;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int len = nums.size();
        vector<long long> res(len);
        DSU dsu(len);
        
        for (int i = removeQueries.size() - 1; i > 0; --i) {
            int j = removeQueries[i];
            dsu.parent[j] = -nums[j];
            if (j - 1 >= 0 and dsu.parent[j - 1] != INT_MAX)
                dsu.merge(j, j - 1);
            if (j + 1 < len and dsu.parent[j + 1] != INT_MAX)
                dsu.merge(j, j + 1);
            res[i - 1] = max(res[i], -dsu.parent[dsu.find(j)]);
        }
        
        return res;
    }
};