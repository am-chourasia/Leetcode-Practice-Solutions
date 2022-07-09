class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        
        std::deque<int> queue;
        queue.push_back(0);
        
        for(int i = 1; i < len; i++) {
            if(queue.front() < i - k) 
                queue.pop_front();       // pop the index which is out of the current window
            dp[i] = nums[i] + dp[queue.front()];
            while(not queue.empty() and dp[queue.back()] <= dp[i])
                queue.pop_back();
            queue.push_back(i);
        }
        return dp.back();
    }
};