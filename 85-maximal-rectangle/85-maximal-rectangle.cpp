class Solution {
    int calculateArea(std::stack<int>& stack, vector<int>& heights, int right_smaller){
        // calculates the area of the top element of the stack 
        // with the help index of smaller element on the left of it, 
        // and index of smaller element on the right of it.
        int idx = stack.top();
        stack.pop();
        int left_smaller = stack.empty() ? -1 : stack.top();
        int area = heights[idx] * (right_smaller - left_smaller - 1);
        return area;
    }
    int largestHistogramArea(vector<int>& heights) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        vector<int> heights(m);

        for(int i=0; i<m; i++)
            heights[i] = (matrix[0][i] == '1') ? 1 : 0;
    
        int ans = largestHistogramArea(heights);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            ans = max(ans, largestHistogramArea(heights));
        }
        return ans;
    }
};