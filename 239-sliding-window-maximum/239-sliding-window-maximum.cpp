class Solution {
  void updateQueue(std::deque<pair<int, int>>& deque, int left, int right, int element) {
    if(not deque.empty() and deque.front().second < left)
      deque.pop_front();
    while(not deque.empty() and deque.back().first <= element)
      deque.pop_back();
    deque.push_back({element, right});
  }
  
  int maxElement(std::deque<pair<int, int>>& deque){
    return deque.front().first;
  }
  
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int len = nums.size();
      vector<int> sliding_max(len - k + 1);
      int left = 0;
      int right = 0;
      
      std::deque<pair<int, int>> deque;
      
      while (right < len) {
        updateQueue(deque, left, right, nums[right]);
        if (right >= k - 1) {
          sliding_max[left] = maxElement(deque);
          left += 1;
        }
        right += 1;
      }
      
      return sliding_max;
    }
};