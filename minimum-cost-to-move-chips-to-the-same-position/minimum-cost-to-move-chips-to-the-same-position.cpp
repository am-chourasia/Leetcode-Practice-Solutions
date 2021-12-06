class Solution {
public:
    int minCostToMoveChips(vector<int>& positions) {
        int odd, even;
        odd = even = 0;
        
        for(int p : positions)
            if(p%2 == 0)
                even++;
            else
                odd++;
        
        int ans = min(odd, even);
        return ans;
    }
};