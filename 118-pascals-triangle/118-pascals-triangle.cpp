class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int rowIndex = 1; rowIndex < numRows; rowIndex++){
            vector<int>& prevRow = ans[rowIndex - 1];
            vector<int>& row = ans[rowIndex];
            row.push_back(1);
            for(int i = 1; i < rowIndex; i++){
                int sum = prevRow[i] + prevRow[i - 1];
                row.push_back(sum);
            }
            row.push_back(1);
        }
        return ans;
    }
};