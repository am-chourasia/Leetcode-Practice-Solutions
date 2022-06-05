class Solution {
    private int n;
    private int m;
    private boolean isValid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    public int nearestExit(char[][] maze, int[] entrance) {
        n = maze.length;
        m = maze[0].length;
        int[] dir = {0, 1, 0, -1, 0};
        var queue = new LinkedList<Pair<Integer, Integer>>();
        int i = entrance[0], j = entrance[1];
        maze[i][j] = 'P';
        
        for(int k = 0; k < 4; k++){
            int x = i + dir[k];
            int y = j + dir[k + 1];
            if(isValid(x, y) && maze[x][y] == '.'){
                maze[x][y] = 'P';
                queue.offer(new Pair<Integer, Integer>(x, y));
            }
        }
        
        int distance = 0;
        while(!queue.isEmpty()){
            distance += 1;
            int nodes = queue.size();    
            for(int __ = 0; __ < nodes; __++){
                var next = queue.poll();
                i = next.getKey(); j = next.getValue();
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k];
                    int y = j + dir[k + 1];
                    if(isValid(x, y)){
                        if(maze[x][y] == '.'){
                            maze[x][y] = 'P';
                            queue.offer(new Pair<Integer, Integer>(x, y));
                        }
                    }
                    else
                        return distance;
                }
            }
        }
        return -1;
    }
}