class Solution {
    static const int PACIFIC = 1;
    static const int ATLANTIC = 2;
    const vector<int> dir = {0, 1, 0, -1, 0};
    int n, m;
    bool isValid(int i, int j){
        if(i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }
    void reachPacificOcean(vector<vector<int>>& grid, vector<vector<int>>& reach){
        for(int j = 0; j < m; j++)
            if(reach[0][j] < PACIFIC)
                spread(grid, reach, 0, j, PACIFIC);
        for(int i = 0; i < n; i++)
            if(reach[i][0] < PACIFIC)
                spread(grid, reach, i, 0, PACIFIC);
    }
    void reachAtlanticOcean(vector<vector<int>>& grid, vector<vector<int>>& reach){
        for(int i = 0; i < n; i++)
            if(reach[i][m - 1] < ATLANTIC)
                spread(grid, reach, i, m - 1, ATLANTIC);
        for(int j = 0; j < m; j++)
            if(reach[n - 1][j] < ATLANTIC)
                spread(grid, reach, n - 1, j, ATLANTIC);
    }
    void spread(vector<vector<int>>& grid, vector<vector<int>>& reach, int i, int j, int ocean){
        reach[i][j] += ocean;
        for(int k = 0; k < 4; k++){
            int newi = i + dir[k];
            int newj = j + dir[k + 1];
            if(isValid(newi, newj) and grid[i][j] <= grid[newi][newj]){ // water can flow up
                if(reach[newi][newj] < ocean)
                    spread(grid, reach, newi, newj, ocean);
            }
        }
    }
    vector<vector<int>> reachBoth(vector<vector<int>>& reach){
        vector<vector<int>> bothReach;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(reach[i][j] == 3)
                    bothReach.push_back({i, j});
            }
        }
        return bothReach;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> reach(n, vector<int>(m, 0));
        
        reachPacificOcean(grid, reach);
        reachAtlanticOcean(grid, reach);
        
        return reachBoth(reach);
    }
};