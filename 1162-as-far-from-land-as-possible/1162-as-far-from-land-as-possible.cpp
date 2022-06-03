class Solution {
    const vector<int> dir = {0, 1, 0, -1, 0};
    int n;
    bool isValid(int i, int j){
        if(i < 0 or i >= n)
            return false;
        if(j < 0 or j >= n)
            return false;
        return true;
    }
    void spread(vector<vector<int>>& grid, std::queue<pair<int, int>>& queue, int level, int i, int j){
        for(int k = 0; k < 4; k++){
            int newi = i + dir[k];
            int newj = j + dir[k + 1];
            if(isValid(newi, newj) and grid[newi][newj] == 0){
                grid[newi][newj] = level;
                queue.push({newi, newj});
            }
        }
        
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        std::queue<pair<int, int>> queue;
        int level = 2;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    spread(grid, queue, level, i, j);
                }
            }
        }
        
        if(queue.size() == 0)
            return -1;
        
        while(queue.size() > 0){
            int nodes = queue.size();
            level++;
            while(nodes--){
                auto [i, j] = queue.front();
                queue.pop();
                spread(grid, queue, level, i, j);
            }
        }
        
        return level - 2;
    }
};