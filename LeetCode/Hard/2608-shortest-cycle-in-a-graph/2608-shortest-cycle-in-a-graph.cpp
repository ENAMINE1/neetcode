class Solution {
    const int INF = 1e9;
    int ans = INF;

    void bfs(int node, vector<vector<int>> & g)
    {
        int n = g.size();
        queue<int> q;
        vector<int> dist(n, INF);
        vector<int> par(n, -1);
        q.push(node);
        dist[node] = 0;

        while(!q.empty())
        {
            int no = q.front();
            q.pop();
            for(auto nn: g[no])
            {
                if(dist[nn] == INF)
                {
                    dist[nn] = dist[no] + 1;
                    par[nn] = no;
                    q.push(nn);
                }
                else if(par[nn] != no && par[no] != nn)
                {
                    ans = min(ans, dist[no] + dist[nn] + 1);
                }
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0],v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i = 1; i<= n; i++)
        {
            bfs(i, g);
        }

        return (ans != INF? ans: -1);
    }
};