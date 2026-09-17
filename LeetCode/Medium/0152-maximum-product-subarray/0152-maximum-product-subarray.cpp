class Solution {
    vector<pair<int,int>> dp;
    vector<int> vis;
    // returns maximum and minimum product of subarray ending at idx
    pair<int,int> rec(int idx, vector<int>& v)
    {
        if(idx == 0)
            return dp[idx] = {v[0], v[0]};
        if(vis[idx])
            return dp[idx];
        // 2 choices for each idx
        // take the current number to be a part of the subarray
        auto [prevMax, prevMin] = rec(idx - 1, v);
        int x = v[idx];
        int currMax = max({x, prevMax * x, prevMin * x});
        int currMin = min({x, prevMax * x, prevMin * x});
        vis[idx] = 1;
        return dp[idx] = {currMax, currMin};
    }

public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n);
        vis.assign(n, 0);
        rec(n - 1, nums);
        int ans = -1e9;
        for(int i = 0; i < n; i++)
            ans = max({ans, dp[i].first, dp[i].second});
        return ans;
    }
};