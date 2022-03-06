#define ll long long
class Solution {
    int mod = 1e9 + 7;
    ll sum(int n){
        return (((ll)(n) * (ll)(n + 1)) / 2ll) % mod;
    }
public:
    int countOrders(int n) {
        int prev = 1;
        int current = 1;
        int positions = 1;
        for(int i = 1; i <= n; i++){
            current = ((ll)prev * sum(positions)) % mod;
            prev = current;
            positions += 2;
        }
        return current;
    }
};