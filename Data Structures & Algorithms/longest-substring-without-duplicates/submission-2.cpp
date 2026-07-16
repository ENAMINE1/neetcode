class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int l = 0; int r = 1;
        unordered_set<char> el;
        el.insert(s[0]);
        int ans = 1;
        while(r < n)
        {
            while(r < n && el.count(s[r]) == 0)
            {
                el.insert(s[r]);
                r++;
            }
            ans = max(ans, int(el.size()));
            while(l <= r && el.count(s[r]))
            {
                el.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};
