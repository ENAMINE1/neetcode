class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        vector<int> ans;
        vector<int> idx(n);
        for(int i = 0;i < n; i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&v](int a, int b){
            return v[a] < v[b];
        });
        int l = 0, hi = n - 1;
        while(l < hi)
        {
            if(v[idx[l]] + v[idx[hi]] > target)
                hi--;
            else if(v[idx[l]] + v[idx[hi]] < target)
                l++;
            else
            {
                ans = {idx[l], idx[hi]};
                break;
            }
        }
        return ans;
    }
};