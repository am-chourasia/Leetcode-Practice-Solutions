class Solution {
    vector<int> prevGreaterElements(vector<int>& height) {
        int len = height.size();
        vector<int> prevGreater(len);
        int maxi = 0;
    
        for (int idx = 0; idx < len; idx++) {
            maxi = max(maxi, height[idx]);
            prevGreater[idx] = maxi;
        }
        return std::move(prevGreater);
    }
    vector<int> nextGreaterElements(vector<int>& height) {
        int len = height.size();
        vector<int> nextGreater(len);
        int maxi = 0;
    
        for (int idx = len - 1; idx >= 0; idx--) {
            maxi = max(maxi, height[idx]);
            nextGreater[idx] = maxi;
        }
        return std::move(nextGreater);
    }
public:
    int trap(vector<int>& height) {
        vector<int> leftGreater = prevGreaterElements(height);
        vector<int> rightGreater = nextGreaterElements(height);
        
        int trapped = 0;
        for (int idx = 0; idx < height.size(); idx++)
            trapped += min(leftGreater[idx], rightGreater[idx]) - height[idx];
        
        return trapped;
    }
};