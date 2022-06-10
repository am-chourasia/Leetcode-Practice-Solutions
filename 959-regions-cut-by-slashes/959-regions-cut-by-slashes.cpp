class Solution {
public:
    void buildGraph(vector<string>& grid, vector<vector<int>>& adj) {
        int n = grid.size()+1;
        int u, v;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-1; j++) {
                if (grid[i][j] == '/') {
                    u = i*n + j+1;
                    v = (i+1)*n + j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                } else if (grid[i][j] == '\\') {
                    u = i*n + j;
                    v = (i+1)*n + j + 1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
    }
    
    void buildCover(vector<vector<int>>& adj, int n) {
        int u = 0, v = n;
        for (int i = 0; i < n-1; i++) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            u += n-1;
            v = u+n;
            adj[u].push_back(v);
            adj[v].push_back(u);
            u++, v = u+n;
        }
        
        for (int i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        
        for (int i = n*(n-1); i < n*n-1; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        
    }
    
    //count cycle
    void dfs(int u, int par, vector<vector<int>>& adj, int& res, vector<int>& v) {
        if (v[u] == 2) return;
        if (v[u] == 1) {
            res++;
            return;
        }
        v[u] = 1;
        for (int i = 0; i < adj[u].size(); i++) {
            if (par != adj[u][i]) dfs(adj[u][i], u, adj, res, v);
        }
        v[u] = 2;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size()+1;
        vector<vector<int>> adj(n*n);
        buildGraph(grid, adj);
        buildCover(adj, n);
        
        int res = 0;
        vector<int> v(n*n, 0);
        
        for (int i = 0; i < n*n; i++) {
            if (v[i] == 0) dfs(i, -1, adj, res, v);
        }
        
        return res;
    }
};