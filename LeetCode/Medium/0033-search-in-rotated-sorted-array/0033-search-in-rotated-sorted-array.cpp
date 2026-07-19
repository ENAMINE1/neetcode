class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int lo = 0, hi = n - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] < v[0]) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        if(v[n - 1] >= target)
        {
            lo = ans;
            hi = n - 1;
        }
        else
        {
            lo = 0;
            hi = ans - 1;
        }
        ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] >= target) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return (v[ans] == target)?ans:-1;
    }
};