class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26);
        int ans = 1;
        int l = 0;
        int maxfreq = 0;
        for(int r = 0; r < n; r++)
        {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            while((r - l + 1) - maxfreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
