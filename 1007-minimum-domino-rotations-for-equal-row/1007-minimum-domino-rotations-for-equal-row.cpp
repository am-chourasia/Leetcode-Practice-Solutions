class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int candidate1 = tops[0];
        int candidate2 = bottoms[0];
        int n = tops.size();
        
        int ans = n + 1;
        
        // for candidate 1:
        {
            int same = 0;
            int flips = 0;
            int possible = true;

            for(int i = 0; i < n; i++){
                if(tops[i] == candidate1 and bottoms[i] == candidate1)
                    same++;
                else if(bottoms[i] == candidate1)
                    flips++;
                else if(tops[i] != candidate1){
                    possible = false;
                    break;
                }
            }
            if(possible)
                ans = min(flips, n - same - flips);
        }
        
        // for candidate 2:
        {
            int same = 0;
            int flips = 0;
            int possible = true;

            for(int i = 0; i < n; i++){
                if(tops[i] == candidate2 and bottoms[i] == candidate2)
                    same++;
                else if(tops[i] == candidate2)
                    flips++;
                else if(bottoms[i] != candidate2){
                    possible = false;
                    break;
                }
            }
            if(possible)
                ans = min({ans, flips, n - same - flips});
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};