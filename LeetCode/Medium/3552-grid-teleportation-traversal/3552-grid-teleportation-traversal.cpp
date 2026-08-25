class Solution {
public:
    int minMoves(vector<string>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        const int INF = 1e9;

        vector<vector<int>> dist(
            m, vector<int>(n, INF)
        );

        // Store positions of each portal.
        vector<vector<pair<int, int>>> pos(26);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] >= 'A' &&
                    matrix[i][j] <= 'Z') {

                    pos[matrix[i][j] - 'A'].push_back({i, j});
                }
            }
        }

        // Whether we have already expanded
        // the teleport edges for this letter.
        vector<bool> used(26, false);

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!dq.empty()) {

            auto [x, y] = dq.front();
            dq.pop_front();

            int d = dist[x][y];

            // ------------------------------------------------
            // 0-cost teleport
            // ------------------------------------------------
            if (matrix[x][y] >= 'A' &&
                matrix[x][y] <= 'Z') {

                int c = matrix[x][y] - 'A';

                if (!used[c]) {

                    used[c] = true;

                    for (auto [nx, ny] : pos[c]) {

                        if (dist[nx][ny] > d) {

                            dist[nx][ny] = d;

                            // Cost = 0
                            dq.push_front({nx, ny});
                        }
                    }
                }
            }

            // ------------------------------------------------
            // 1-cost normal movement
            // ------------------------------------------------
            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n ||
                    matrix[nx][ny] == '#') {
                    continue;
                }

                if (dist[nx][ny] > d + 1) {

                    dist[nx][ny] = d + 1;

                    // Cost = 1
                    dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] == INF
                   ? -1
                   : dist[m - 1][n - 1];
    }
};