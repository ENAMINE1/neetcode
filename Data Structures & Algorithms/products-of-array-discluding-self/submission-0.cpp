class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count_zeros = 0;
        int product = 1;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                count_zeros++;
            else
                product *= nums[i];
        }
        if (count_zeros == 0) {
            for (int i = 0; i < n; i++) {
                ans.push_back(product / nums[i]);
            }
        } else if (count_zeros == 1) {
            for (int i = 0; i < n; i++) {
                if(nums[i] == 0)
                {
                    ans.push_back(product);
                }
                else
                    ans.push_back(0);
            }
        }else
            for(int i = 0; i < n; i++)
                ans.push_back(0);
        return ans;
    }
};
