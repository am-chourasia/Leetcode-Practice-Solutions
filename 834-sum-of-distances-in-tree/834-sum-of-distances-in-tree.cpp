class Solution {
    vector<vector<int>> graph;
    vector<int> distance;
    vector<int> strength;
    int n;
    
    int calculateFirstNode(int node, int parent, int depth){
        distance[0] += depth;
        strength[node] += 1;
        for(int adj : graph[node]){
            if(adj != parent)
                strength[node] += calculateFirstNode(adj, node, depth + 1);
        }
        return strength[node];
    }
    void calculateAllNodes(int node,int parent){
        if(parent != -1)
            distance[node] = distance[parent] - 2 * strength[node] + n;
        for(int adj : graph[node]){
            if(adj != parent)
                calculateAllNodes(adj, node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        graph.resize(n);
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        distance.resize(n);
        strength.resize(n);
        calculateFirstNode(0, -1, 0);
        calculateAllNodes(0, -1);
        return distance;
    }
};