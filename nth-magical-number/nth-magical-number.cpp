class Solution {
    int mod = 1000000007;
    int findLcm(int a, int b){
        int gcd = __gcd(a,b);
        return (a * b)/gcd;
    }
    int numberOfElements(int mul, int small, int large){
        // counts the number of element within mul * large:
        return mul + (mul * large)/small;
    }
    int findTarget(int small, int large, int target, int lcm){
        int left = 1, right = lcm / large;
        while(left <= right){
            int mid = (left + right)/2;
            int elementsCovered = numberOfElements(mid, small, large);
            if(elementsCovered == target)
                return large * mid;
            if(elementsCovered < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        left--;
        int mul = (large * left) / small;   // number of factors of smaller number already added
        mul += (target - numberOfElements(left, small, large)); // number of factors to be added;
        return small * mul;
    }
    int calculateAns(long lcm, long multiplier, long val){
        return (val + (lcm * multiplier) % mod) % mod;
    }
public:
    int nthMagicalNumber(int target, int a, int b) {
        if(a == b)
            return ((long)a * (long)target) % mod;
        int lcm = findLcm(a, b);
        int window = lcm/a + lcm/b - 1;
        int multiplier = target / window;
        target = target - (window * multiplier);
        int val = findTarget(min(a,b), max(a,b), target, lcm);
        return calculateAns(lcm, multiplier, val);
    }
};