class Solution {
    void markNetwork(int computer, vector<vector<int>>& graph, vector<bool>& visited){
        visited[computer] = true;
        for(int neighbour : graph[computer])
            if(not visited[neighbour])
                markNetwork(neighbour, graph, visited);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalConnections = connections.size();
        if(totalConnections < n - 1)
            return -1;
        
        vector<vector<int>> graph(n);
        for(auto& connection : connections){
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n);
        int components = 0;
        
        for(int computer = 0; computer < n; computer++){
            if(not visited[computer]){
                markNetwork(computer, graph, visited);
                components++;
            }
        }
        
        return components - 1;
    }
};