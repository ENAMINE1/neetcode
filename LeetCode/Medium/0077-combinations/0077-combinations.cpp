class Solution {
    vector<vector<int>> ans;
    map<int, int> taken;
    void rec(int idx, int n, int k, vector<int>& temp) {
        if(idx == n + 2)
            return;
        if (k == 0) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(idx);
        rec(idx + 1, n, k - 1, temp);
        temp.pop_back();
        rec(idx + 1, n, k, temp);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        rec(1, n, k, temp);
        return ans;
    }
};