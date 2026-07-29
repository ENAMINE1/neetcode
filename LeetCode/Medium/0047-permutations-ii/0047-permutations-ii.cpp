class Solution {
    vector<vector<int>> ans;
    map<int, int> freq;

    void rec(int lvl, vector<int>& temp, vector<int>& v) {
        int n = v.size();
        if (lvl == n + 1) {
            ans.push_back(temp);
            return;
        }
        for (auto [a, b] : freq) {
            if (freq[a] > 0) {
                freq[a]--;
                temp.push_back(a);
                rec(lvl + 1, temp, v);
                temp.pop_back();
                freq[a]++;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto& e : nums)
            freq[e]++;
        vector<int> temp;
        rec(1, temp, nums);
        return ans;
    }
};