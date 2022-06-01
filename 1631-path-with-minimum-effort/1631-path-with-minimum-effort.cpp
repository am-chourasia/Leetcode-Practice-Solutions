class Solution {
    int n, m;
    vector<vector<int>> direction = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    bool isValid(int i, int j){
        if(i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        // {cost, i, j};
        
        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        costs[0][0] = 0;
        pq.push({0, 0, 0});
        
        while(not pq.empty()){
            const vector<int>& ref = pq.top();
            int cost = ref[0];
            int row = ref[1];
            int col = ref[2];
            visited[row][col] = true;
            int currentCost = costs[row][col];
            pq.pop();
            
            for(vector<int>& dir : direction){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if(isValid(newRow, newCol) and not visited[newRow][newCol]){
                    int jump = max(cost, abs(grid[row][col] - grid[newRow][newCol]));
                    if(jump < costs[newRow][newCol]){
                        costs[newRow][newCol] = jump;
                        pq.push({jump, newRow, newCol});
                    }
                }
            }
        }
        
        return costs[n-1][m-1];
    }
};