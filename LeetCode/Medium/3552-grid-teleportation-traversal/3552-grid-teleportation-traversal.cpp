class Solution {

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

public:
    int minMoves(vector<string>& v) {
        int n = v.size();
        int m = v[0].size();

        deque<pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        dq.push_back({0, 0});
        vector<int> vis(26, 0);
        // mark the positions of all the alphabets
        vector<vector<pair<int, int>>> idx_v(26);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] >= 'A' && v[i][j] <= 'Z')
                    idx_v[v[i][j] - 'A'].push_back({i, j});
            }
        }

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < n && ny < m && nx >= 0 && ny >= 0 &&
                    v[nx][ny] != '#') {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        dq.push_back({nx, ny});
                    }
                }
            }

            if(v[x][y] != '.' && !vis[v[x][y] - 'A'])
            {
                vis[v[x][y] - 'A'] = 1;
                for (auto [nx, ny] : idx_v[v[x][y] - 'A']) {
                    if(dist[nx][ny] > dist[x][y]) {
                        dist[nx][ny] = dist[x][y];
                        dq.push_front({nx, ny});
                    }
                }
            }
        }

        return (dist[n - 1][m - 1] == 1e9)?-1: dist[n -1][m - 1];
    }
};