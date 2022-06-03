class Solution {
    int n, m;
    bool isValid(int i, int j){
        if(i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
                
        n = grid.size();
        m = grid[0].size();
        vector<int> direction = {0, 1, 0, -1, 0};
        
        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        costs[0][0] = 0;
        
        std::deque<vector<int>> deque;
        deque.push_back({0, 0, 0});
        
        while(not deque.empty()){
            const vector<int>& ref = deque.front();
            int cost = ref[0], row = ref[1], col = ref[2];
            deque.pop_front();
            
            if(row == n - 1 and col == m - 1)
                return cost;
            
            for(int i = 0; i < 4; i++){
                int newRow = row + direction[i];
                int newCol = col + direction[i + 1];
                if(isValid(newRow, newCol) and costs[newRow][newCol] == INT_MAX){
                    costs[newRow][newCol] = cost + grid[newRow][newCol];
                    if(grid[newRow][newCol] == 1)
                        deque.push_back({cost + 1, newRow, newCol});
                    else 
                        deque.push_front({cost, newRow, newCol});
                }
            }
        }
        
        return costs[n-1][m-1];
    }
};