class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<pair<int, int>> T;
        for(auto b: buildings){
            T.insert({b[0], -b[2]});
            T.insert({b[1], b[2]});
        }
        
        multiset<int> stack({0});
        
        int top = 0, prevtop = 0;
        vector<vector<int>> ans;
        
        for(auto t: T){
            prevtop = top;
            
            if(t.second<0)
                stack.insert(abs(t.second));
            else
                stack.erase(stack.lower_bound(t.second));
            
            top = *(--stack.end());
            
            if(top != prevtop){
                ans.push_back({t.first, top});
            }
        }
        return ans;
    }
};