class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int j = 0;
        vector<vector<int>> ans;
        for(int i = j; i < n;)
        {
            auto v = intervals[j];
            int start = v[0];
            int end = v[1];
            int interval_end = end;
            while(i < n && intervals[i][0] <= interval_end)
            {
                interval_end = max(interval_end, intervals[i][1]);
                i++;
            }
            ans.push_back({start, interval_end});
            j = i;
        }
        return ans;
    }
};