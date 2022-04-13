class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int top = 0, down = n - 1;
        int element = 1;
        
        while(element <= n * n){
            for(int j = left; j <= right; j++)
                ans[top][j] = element++;
            top++;
            for(int i = top; i <= down; i++)
                ans[i][right] = element++;
            right--;
            for(int j = right; j >= left; j--)
                ans[down][j] = element++;
            down--;
            for(int i = down; i >= top; i--)
                ans[i][left] = element++;
            left++;
        }
        
        return ans;
    }
};