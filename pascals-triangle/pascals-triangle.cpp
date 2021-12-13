class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        numRows--;
        while(numRows--){
            vector<int> t;
            t.push_back(1);
            for(int i = 1; i<ans.back().size(); i++){
                t.push_back(ans.back()[i] + ans.back()[i-1]);
            }
            t.push_back(1);
            ans.push_back(t);
        }
        return ans;
    }
};