class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
                break;
            // getting rid of duplicates
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int start = i + 1;
            int end = n - 1;
            int target = -nums[i];
            while(start < end)
            {
                if(nums[start] + nums[end] > target)
                    end--;
                else if (nums[start] + nums[end] < target)
                    start++;
                else
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start - 1])
                        start++;                    
                }
            }
        }
        return ans;
    }
};
