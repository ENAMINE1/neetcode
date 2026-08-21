class Solution {
    int ans = 0;

    vector<int> vis;
    vector<int> par;

    void dfs(int node, int parent, vector<vector<int>>& g) {
        vis[node] = 2;
        par[node] = parent;

        for (auto nn : g[node]) {
            if (vis[nn] == 1) {
                dfs(nn, node, g);
            } else if (vis[nn] == 2) {
                int temp = node;
                int cnt = 0;
                while (nn != temp) {
                    cnt++;
                    temp = par[temp];
                }
                cnt++;
                ans = max(ans, cnt);
            }
        }
        vis[node] = 3;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n);
        vis.assign(n, 1);
        par.assign(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(edges[i] != -1)
                g[i].push_back(edges[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 1)
                dfs(i, -1, g);
        }

        return (ans == 0? -1: ans);
    }
};