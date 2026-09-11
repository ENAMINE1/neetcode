class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(mp.count(target - v[i]) != 0)
            {
                ans = {mp[target - v[i]], i};
                sort(ans.begin(), ans.end());
                break;
            }
            else
                mp[v[i]] = i;
        }
        return ans;
    }
};