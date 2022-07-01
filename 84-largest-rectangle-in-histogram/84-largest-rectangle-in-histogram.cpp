class Solution {
    int calculateArea(std::stack<int>& stack, vector<int>& heights, int right_smaller){
        int idx = stack.top();
        stack.pop();
        int left_smaller = stack.empty() ? -1 : stack.top();
        int area = heights[idx] * (right_smaller - left_smaller - 1);
        return area;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        std::stack<int> stack;
        int maxArea = 0;
        
        for(int i = 0; i < len; i++){
            while(not stack.empty() and heights[stack.top()] > heights[i])
                maxArea = max(calculateArea(stack, heights, i), maxArea);
            stack.push(i);
        }
        while(not stack.empty())
            maxArea = max(calculateArea(stack, heights, len), maxArea);
        
        return maxArea;
    }
};