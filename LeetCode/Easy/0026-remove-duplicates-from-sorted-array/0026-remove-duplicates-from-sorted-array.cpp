class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        set<int> s;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(s.count(v[i]) == 0)
            {
                ans[j] = v[i];
                j++;
            }
            s.insert(v[i]);
        }
        v = ans;
        return j;
    }
};