class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        std::stack<int> stack;
        int maxArea = 0;
        
        for(int i = 0; i < len; i++){
            while(not stack.empty() and heights[stack.top()] > heights[i]){
                int idx = stack.top();
                stack.pop();
                int left_smaller = stack.empty() ? -1 : stack.top();
                int right_smaller = i;
                int area = heights[idx] * (right_smaller - left_smaller - 1);
                maxArea = max(area, maxArea);
            }
            stack.push(i);
        }
        while(not stack.empty()){
            int idx = stack.top();
            stack.pop();
            int left_smaller = stack.empty() ? -1 : stack.top();
            int right_smaller = len;
            int area = heights[idx] * (right_smaller - left_smaller - 1);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};