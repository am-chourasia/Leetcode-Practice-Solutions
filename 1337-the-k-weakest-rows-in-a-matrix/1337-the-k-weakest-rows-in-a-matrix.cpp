class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int height = mat.size();
        int width = mat[0].size();
        vector<pair<int, int>> strength(height);
        
        for(int row = 0; row < height; row++){
            int count = 0;
            for(int col = 0; col < width; col++)
                count += mat[row][col];
            strength[row] = {count, row};
        }
        
        sort(strength.begin(), strength.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = strength[i].second;
        
        return ans;
    }
};