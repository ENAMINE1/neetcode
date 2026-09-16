class Solution {

    vector<vector<vector<int>>> dp;

    // given the choice to buy on day idx what is the max profit gained till day n using 2 transactions
    int rec(int idx, int tx_left, int can_buy, vector<int>& p)
    {
        int n = p.size();
        // cannot buy or sell so can not gain any more porfit
        if(idx == n || tx_left == 0)
            return 0;
        if(dp[idx][tx_left][can_buy] != -1)
            return dp[idx][tx_left][can_buy];
        int profit = 0;
        if(can_buy)
        {
            int buy = -p[idx] + rec(idx + 1, tx_left, 0, p);
            int dont_buy = rec(idx + 1, tx_left, 1, p);
            profit = max(buy, dont_buy);
        }
        else
        {
            int sell = p[idx] + rec(idx + 1, tx_left - 1, 1, p);
            int dont_sell = rec(idx + 1, tx_left, 0, p);
            profit = max(sell, dont_sell);
        }
        return dp[idx][tx_left][can_buy] = profit;
    }

public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        dp.assign(n + 1, vector<vector<int>>(3,vector<int>(2, -1)));
        return rec(0, 2, 1, p);
    }
};