class Solution {
    map<char, int> freq;

    int rec(int lvl, string tiles) {
        int n = tiles.length();
        int ret = 0;
        for (auto [c, f] : freq) {
            if (f > 0) {
                freq[c]--;
                ret += rec(lvl + 1, tiles) + 1;
                freq[c]++;
            }
        }
        return ret;
    }

public:
    int numTilePossibilities(string tiles) {
        for (auto& c : tiles)
            freq[c]++;
        return rec(0, tiles);
    }
};