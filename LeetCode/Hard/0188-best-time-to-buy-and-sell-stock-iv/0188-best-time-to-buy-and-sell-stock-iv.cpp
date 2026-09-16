class Solution {

    vector<vector<int>> dp;

    int rec(int idx, int tx_left, vector<int>& p)
    {
        if(tx_left == 0)
            return 0;
        if(idx < 0)
        {
            return -1e9;
        }
        if(dp[idx][tx_left] != -1)
            return dp[idx][tx_left];
        int profit = 0;
        for(int buy_idx = 0; buy_idx < idx; buy_idx++)
        {
            int diff = p[idx] - p[buy_idx];
            if(diff > 0){
                profit = max(profit, rec(buy_idx, tx_left - 1, p) + diff);
            }
        }
        profit = max(profit, rec(idx - 1, tx_left, p));
        return dp[idx][tx_left] = profit;
    }

public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return rec(n - 1, k, p);
    }
};