class Solution {

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

public:
    int minCost(vector<vector<int>>& grid) {
        // construct the graph
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        pair<int, int> start = {0, 0};

        deque<pair<int,int>> dq;
        dq.push_front(start);
        dist[0][0] = 0;
        while(!dq.empty())
        {
            auto node = dq.front();
            dq.pop_front();

            for(int i = 0; i < 4; i++)
            {
                int nx = node.first + dx[i];
                int ny = node.second + dy[i];
                
                if(nx >= n || nx < 0 || ny >= m || ny < 0)
                    continue;
                
                int cost = (i + 1 != grid[node.first][node.second]);
                if(dist[nx][ny] > dist[node.first][node.second] + cost)
                {
                    if(cost)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});

                    dist[nx][ny] = dist[node.first][node.second] + cost;
                }
            }
        }  
        return dist[n - 1][m - 1];    
    }
};