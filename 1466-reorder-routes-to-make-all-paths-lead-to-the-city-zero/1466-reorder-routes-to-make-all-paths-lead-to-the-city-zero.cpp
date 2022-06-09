class Solution {
    auto buildGraph(int n, vector<vector<int>>& connections){
        vector<vector<pair<int, int>>> graph(n);
        for(const vector<int>& connection : connections){
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }
        return graph;
    }
    int traverse(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited){
        visited[node] = true;
        int invertedEdges = 0;
        for(const auto& [adj, weight] : graph[node])
            if(not visited[adj])
                invertedEdges += traverse(adj, graph, visited) + weight;
        return invertedEdges;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        auto graph = buildGraph(n, connections);
        vector<bool> visited(n, false);
        int revertedEdges = traverse(0, graph, visited);
        return revertedEdges;
    }
};