class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            int r = heights[i];
            for(int j = 0; j < i; j++)
            {
                int l = heights[j];
                ans = max(ans, min(r,l) * (i - j));
            }
        }
        return ans;
    }
};
