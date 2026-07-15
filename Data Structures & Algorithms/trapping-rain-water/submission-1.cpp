class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> l(n,0), r(n,0);
        int maxl = 0, maxr = 0;
        for(int i = 0; i < n; i++)
        {
            l[i] = maxl;
            maxl = max(h[i], maxl);
            r[n - i - 1] = maxr;
            maxr = max(h[n - i - 1], maxr);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int x = min(l[i], r[i]);
            if(x > h[i])
                ans += x - h[i];
            // cout<<x<<" "<<l[i]<<" "<<r[i]<<" "<<h[i]<<" "<<ans<<endl;
        }
        return ans;
    }
};
