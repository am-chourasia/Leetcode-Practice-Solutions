class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return vector<int>({0});
        // We keep removing the leaf nodes until only one or two nodes exists
        // The node at the maximum depth, the ones that remain at the last,
        // is surely the root with minimum height
        // In other words, we keep peeling the layers of the graph until we reach the last layer.
        vector<vector<int>> graph(n);
        std::vector<int> degree(n); // the degree of each node
        std::vector<int> layer(n); // to mark the depth at which the node is removed
        std::queue<int> q;
        
        // building graph and calculating degree on go
        for(vector<int>& nodes: edges){
            int node1 = nodes[0], node2 = nodes[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            degree[node1]++;
            degree[node2]++;
        }
        
        // adding all degree 1 nodes to queue for processing 
        // and marking the nodes as layer 1: the first one to get removed
        for(int i=0; i<n; i++){
            if(degree[i] == 1){
                q.push(i);
                layer[i] = 1;
            }
        }
        
        int maxDepth = 1, node;
        while(!q.empty()){
            node = q.front(), q.pop();
            // all the adjacent nodes connected to this leaf node is checked:
            // if the updated degree of the adjacent node become 1 after removing the leaf,
            // add it to the queue as it becomes a leaf node for next process
            for(int& connectedNode: graph[node]){
                // if it was already one, it must be already present in the queue
                if(degree[connectedNode] != 1){
                    degree[connectedNode]--;
                    if(degree[connectedNode] == 1){
                        q.push(connectedNode);
                        layer[connectedNode] = layer[node] + 1;
                        maxDepth = max(maxDepth, layer[connectedNode]);
                    }
                }
            }
        }
        
        vector<int> ans;
        
        // the last layered nodes are added to the answer
        for(int i=0; i<n; i++)
            if(layer[i] == maxDepth)
                ans.push_back(i);
        
        return ans;
    }
};