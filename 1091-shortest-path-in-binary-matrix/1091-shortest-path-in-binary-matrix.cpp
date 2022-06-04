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
        
        std::queue<Point> queue;
        queue.push({0, 0});
        int distance = 0;
        
        while(not queue.empty()){
            int level = queue.size();
            distance++;
            while(level--){
                Point point = queue.front(); queue.pop();
                
                if(point.i == n-1 and point.j == n-1)
                    return distance;
                
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        int x = point.i + i, y = point.j + j;
                        if(isValid(x, y) and grid[x][y] == 0){
                            grid[x][y] = 1;
                            queue.push({x, y});
                        }
                    }
                }
            }            
        }
        return -1;
    }
};