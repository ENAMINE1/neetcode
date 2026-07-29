class Solution {
    vector<vector<int>>  ans;

    void rec(int idx, vector<int>&temp, vector<int> &v)
    {
        int n = v.size();
        if(idx == n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(v[idx]);
        rec(idx + 1, temp, v);
        temp.pop_back();
        while(idx + 1 < n && v[idx] == v[idx + 1])
            idx++;
        rec(idx + 1, temp, v);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<int> temp;
        rec(0,temp,v);
        return ans;
    }
};