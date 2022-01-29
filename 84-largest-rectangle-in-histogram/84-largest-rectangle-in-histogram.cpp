class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        std::stack<int> stack;              // will store the index
        std::vector<int> dist(n);
        
        for(int i=0; i<n; i++){
            while(!stack.empty() and heights[i] < heights[stack.top()]){
                dist[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            dist[stack.top()] = n - stack.top();
            stack.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            while(!stack.empty() and heights[i] < heights[stack.top()]){
                dist[stack.top()] += stack.top() - i - 1;
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            dist[stack.top()] += stack.top();
            stack.pop();
        }
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, dist[i] * heights[i]);
        return ans;
    }
};