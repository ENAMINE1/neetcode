class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int tail = 0;
        int head = -1;
        int ans = 0;
        set<char> ss;
        while(tail < n)
        {
            // extend head till i can
            while(head + 1 < n && ss.count(s[head + 1]) == 0)
            {
                head++;
                // update to latest index
                ss.insert(s[head]);
            }
            ans = max(ans, head - tail + 1);
            // move tail to make the subarry feasable again
            if(head < tail)
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                ss.erase(s[tail]);
                tail++;
            }
        }
        return ans;
    }
};