class Solution {
public:
    int brokenCalc(int start, int target) {
        int ans = 0;
        while(target > start){
            ans++;
            if(target & 1)
                target++;
            else
                target >>= 1;
        }
        
        return ans + start - target;
    }
};