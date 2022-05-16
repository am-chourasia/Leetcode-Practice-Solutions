struct Point{
    int i;
    int j;
};
class Solution {
    int n;
    bool isValid(int i, int j){
        if(i < 0 or i >= n)
            return false;
        if(j < 0 or j >= n)
            return false;
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] == 1)
            return -1;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        const vector<Point> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1}, { 0, 0}, { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };
        
        std::queue<Point> queue;
        queue.push({0, 0});
        int distance = 0;
        
        while(not queue.empty()){
            int level = queue.size();
            distance++;
            while(level--){
                Point point = queue.front(); 
                queue.pop();
                if(point.i == n-1 and point.j == n-1)
                    return distance;
                
                for(auto [i, j] : dir){
                    int newI = point.i + i;
                    int newJ = point.j + j;
                    if(isValid(newI, newJ) 
                       and grid[newI][newJ] == 0 
                       and not visited[newI][newJ]
                      ){
                        queue.push({newI, newJ});
                        visited[newI][newJ] = true;
                    }
                }
            }            
        }
        return -1;
    }
};