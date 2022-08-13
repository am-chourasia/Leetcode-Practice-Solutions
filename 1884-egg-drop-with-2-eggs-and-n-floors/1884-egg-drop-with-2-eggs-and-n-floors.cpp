class Solution {
public:
    int twoEggDrop(int n) {
        int high = 100, low = 0;
        while(low + 1 < high){
            int mid = (high + low) / 2;
            if(mid * (mid + 1) >= n * 2)
                high = mid;
            else
                low = mid;
        }
        return high;
    }
};