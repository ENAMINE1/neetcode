class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<int>> rows(n), cols(n);
        vector<vector<unordered_set<int>>> boards(n / 3, vector<unordered_set<int>>(n / 3));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int curr = board[i][j] - '0';
                    bool faulty = cols[j].count(curr) ||
                                  rows[i].count(curr) ||
                                  boards[i / 3][j / 3].count(curr);

                    if (faulty) return false;

                    rows[i].insert(curr);
                    cols[j].insert(curr);
                    boards[i / 3][j / 3].insert(curr);
                }
            }
        }
        return true;
    }
};
