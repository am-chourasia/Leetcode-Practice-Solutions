class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> graph(n);
        vector<int> degree(n);
        
        for(vector<int>& road : roads){
            int from = road[0];
            int to = road[1];
            graph[from].insert(to);
            graph[to].insert(from);
            degree[to]++;
            degree[from]++;
        }
        int maxRank = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int rank = degree[i] + degree[j] - graph[i].count(j);
                cout << i << " " << j << " " << rank << endl;
                maxRank = max(rank, maxRank);
            }
        }
        
        return maxRank;
    }
};