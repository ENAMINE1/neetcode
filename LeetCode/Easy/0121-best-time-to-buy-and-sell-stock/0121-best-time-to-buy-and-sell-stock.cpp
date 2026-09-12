class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int mn = p[0];
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            ans = max(ans, p[i] - mn);
            mn = min(mn, p[i]);
        }
        return ans;
    }
};