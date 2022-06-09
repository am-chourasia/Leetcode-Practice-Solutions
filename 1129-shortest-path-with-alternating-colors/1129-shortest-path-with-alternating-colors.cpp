class Solution {
    const int inf = 200;
    const int RED = 0;
    const int BLUE = 1;
    void buildGraph(vector<vector<vector<int>>>& graph, vector<vector<int>>& edges, int color){
        for(const vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u][color].push_back(v);
        }
    }
    void findReach(vector<vector<vector<int>>>& graph, vector<vector<int>>& reach, int color){
        std::queue<int> queue;
        queue.push(0);
        int distance = 0;
        while(not queue.empty()){
            int level = queue.size();
            distance++;
            while(level--){
                int node = queue.front(); queue.pop();
                for(int adj : graph[node][color]){
                    if(reach[adj][color] > distance){
                        reach[adj][color] = distance;
                        queue.push(adj);
                    }
                }
            }
            color = color xor BLUE;
        }
    }
    vector<int> findShortestPath(vector<vector<int>>& reach){
        int n = reach.size();
        vector<int> shortestPath(n);
        for(int i = 1; i < n; i++){
            shortestPath[i] = min(reach[i][RED], reach[i][BLUE]);
            if(shortestPath[i] == inf)
                shortestPath[i] = -1;
        }
        return shortestPath;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>(2));
        buildGraph(graph, redEdges, RED);
        buildGraph(graph, blueEdges, BLUE);
        
        vector<vector<int>> reach(n, vector<int>(2, inf));
        findReach(graph, reach, RED);
        findReach(graph, reach, BLUE);
        
        return findShortestPath(reach);
    }
};