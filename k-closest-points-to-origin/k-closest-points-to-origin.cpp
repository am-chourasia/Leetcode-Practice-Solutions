class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> S(compare);
        
        for(vector<int>& p : points){
            if(S.size() < k)
                S.push(p);
            else if(compare(p, S.top())){
                S.pop();
                S.push(p);
            }
        }
        
        vector<vector<int>> ans;
        while(!S.empty()){
            ans.push_back(S.top());
            S.pop();
        }
        return ans;
    }
};