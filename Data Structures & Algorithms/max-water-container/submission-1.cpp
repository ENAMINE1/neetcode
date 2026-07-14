class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int start = 0, end = n -1;
        int ans = 0;
        while(start < end)
        {
            ans = max(ans, min(heights[start], heights[end]) * (end - start));
            if(heights[start] <= heights[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};
