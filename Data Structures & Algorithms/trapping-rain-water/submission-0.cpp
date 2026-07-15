class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        map<int, vector<int>, greater<int>> mp;
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int he = h[i]; he >= 0; he--)
            {
                mp[he].push_back(i);
            }
            mx = max(mx, h[i]);
        }
        for(auto it = mp.begin(); next(it) != mp.end(); it++)
        {
            int width = it->first - next(it)->first;
            int length = 0;
            vector<int> &vec = it->second;
            for(int i = 1; i < vec.size(); i++)
            {
                length+= vec[i] - vec[i - 1] - 1;
            }
            ans += length * width;
        }
        return ans;
    }
};
