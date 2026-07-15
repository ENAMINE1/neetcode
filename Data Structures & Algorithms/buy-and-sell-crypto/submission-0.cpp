class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> v(n);
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            mx = max(mx, p[n - i - 1]);
            v[n - i - 1] = mx;
            ans = max(ans, v[n - i - 1] - p[n - i - 1]);
        }
        return ans;
    }
};
