class Solution {

    vector<int> dp;
    // largest subarray sum ending at idx and starting somewhere before or on idx
    int rec(int idx, vector<int> &nums)
    {
        if(idx == -1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        // 2 choices take the current number in the subarray sum if the subarray sum is positive
        int ans = 0;
        if(rec(idx - 1, nums) >= 0)
            ans = rec(idx - 1, nums) + nums[idx];
        else
            ans = nums[idx];
        // cout<<idx<<" "<<ans<<endl;
        return dp[idx] = ans;
    }

public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        rec(n - 1, nums);
        int ans = -1e9;
        for(int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};