class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), post(n);
        pre[0] = nums[0];
        post[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
            post[n - i - 1] = post[n - i] * nums[n - i - 1];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(((i - 1) >= 0 ? pre[i - 1] : 1) * ((i + 1) < n ? post[i + 1] : 1));
        }
        return ans;
    }
};
