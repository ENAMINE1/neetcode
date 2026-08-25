class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i == n - 1 && j == m - 1)
            return true;

        grid[i][j] = 0;

        if (i + 1 < n && grid[i + 1][j] &&
            dfs(grid, i + 1, j))
            return true;

        if (j + 1 < m && grid[i][j + 1] &&
            dfs(grid, i, j + 1))
            return true;

        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Remove one arbitrary path.
        dfs(grid, 0, 0);

        // If no second path exists, one cell on the
        // first path can disconnect the grid.
        return !dfs(grid, 0, 0);
    }
};