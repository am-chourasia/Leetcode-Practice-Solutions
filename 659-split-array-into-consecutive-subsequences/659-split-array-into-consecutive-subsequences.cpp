class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> remaining;
        map<int, int> endsAt;
        
        for (int num : nums)
            remaining[num] += 1;
        
        for (int num : nums) {
            if (remaining[num]) {
                remaining[num] -= 1;
                if (endsAt[num - 1] > 0) {
                    endsAt[num - 1] -= 1;
                    endsAt[num] += 1;
                }
                else if (remaining[num + 1] and remaining[num + 2]) {
                    remaining[num + 1] -= 1;
                    remaining[num + 2] -= 1;
                    endsAt[num + 2] += 1;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};