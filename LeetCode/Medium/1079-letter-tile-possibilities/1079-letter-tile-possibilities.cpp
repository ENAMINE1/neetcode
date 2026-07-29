class Solution {
    int ans = 0;
    map<char, int> freq;

    void rec(int lvl, string tiles) {
        int n = tiles.length();
        ans++;
        if (lvl == n) {
            return;
        }
        for (auto [c, f] : freq) {
            if (f > 0) {
                freq[c]--;
                rec(lvl + 1, tiles);
                freq[c]++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        for (auto& c : tiles)
            freq[c]++;
        rec(0, tiles);
        return ans - 1;
    }
};