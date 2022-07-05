class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        int ans = 0;
        for(int& i:nums)
            s.insert(i);
        
        for(int i: nums){
            if(s.count(i-1) == 0){
                int count = 1;
                while(s.count(++i)){
                    s.erase(i);
                    count++;
                }
                ans = max(ans, count);                    
            }
        }
        return ans;
    }
};