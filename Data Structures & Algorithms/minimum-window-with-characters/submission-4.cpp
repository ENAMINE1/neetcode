class Solution {
private:
    bool found(vector<int> &freq, vector<int> &runningfreq)
    {
        for(int i = 0; i < 128; i++)
        {
            if(freq[i] > 0 && freq[i] > runningfreq[i])
                return false;            
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> freq(128), runningfreq(128);
        int l = 0;
        int mn = INT_MAX;
        string ans = "";
        for(int i = 0; i < m; i++)
        {
            freq[t[i] - 'A']++;
        }
        for(int r = 0; r < n; r++)
        {
            runningfreq[s[r] - 'A']++;
            while(l <= r && found(freq, runningfreq))
            {
                if(r - l + 1 < mn)
                {
                    cout<<r<<" "<<l<<" "<<mn<<endl;
                    mn = r- l + 1;
                    ans = s.substr(l, mn);
                }
                runningfreq[s[l] - 'A']--;
                l++;
            }
        }
        return ans;
    }
};
