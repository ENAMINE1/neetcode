class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int, greater<int>> mp;
        for(int i = 0; i < k; i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(int j = k; j <= n; j++)
        {
            ans.push_back(mp.begin()->first);
            mp[nums[j - k]]--;
            if(mp[nums[j - k]] == 0)
                mp.erase(nums[j - k]);
            if(j == n)
                break;
            mp[nums[j]]++;
        }
        return ans;
    }
};