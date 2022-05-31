class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n + 1);
        for(vector<int>& edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        // timing, node;
        
        vector<int> timing(n + 1, INT_MAX);
        timing[k] = 0;
        pq.push({0, k});
        
        while(not pq.empty()){
            auto [currentTime, node] = pq.top();
            pq.pop();
            
            for(auto& [neighbour, time] : graph[node]){
                int newTime = time + currentTime;
                if(newTime < timing[neighbour]){
                    timing[neighbour] = newTime;
                    pq.push({newTime, neighbour});
                }
            }
        }
        
        int ans = -1;
        for(int i = 1; i <= n; i++)
            ans = max(ans, timing[i]);
        
        if(ans == INT_MAX)
            return -1;
    
        return ans;
    }
};
