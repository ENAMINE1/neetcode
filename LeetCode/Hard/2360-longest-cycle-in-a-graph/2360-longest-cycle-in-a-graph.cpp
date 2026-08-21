class Solution {
    int ans = 0;

    vector<int> vis;
    vector<int> depth;

    void dfs(int node, int d, vector<vector<int>>& g) {
        vis[node] = 2;
        depth[node] = d;

        for (auto nn : g[node]) {
            if (vis[nn] == 1) {
                dfs(nn, d + 1, g);
            } else if (vis[nn] == 2) {
                ans = max(ans, depth[node] - depth[nn] + 1);
            }
        }
        vis[node] = 3;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n);
        vis.assign(n, 1);
        depth.assign(n, 0);

        for(int i = 0; i < n; i++)
        {
            if(edges[i] != -1)
                g[i].push_back(edges[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 1)
                dfs(i, 0, g);
        }

        return (ans == 0? -1: ans);
    }
};