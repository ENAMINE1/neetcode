class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> v;
        int ans = 0;
        for(int i = 0; i< n; i++)
        {
            v.insert(nums[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(v.count(nums[i] - 1) == 0)
            {
                int curr = nums[i];
                int cnt = 0;
                while(v.count(curr) != 0)
                {
                    cnt++;
                    curr++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
