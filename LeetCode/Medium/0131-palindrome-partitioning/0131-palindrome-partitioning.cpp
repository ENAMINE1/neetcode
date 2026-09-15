class Solution {
    vector<vector<string>> ans;

    int isPalindrome[20][20];

    void rec(int idx, string& s, vector<string>& arr) {
        int n = s.length();
        if (idx == n) {
            ans.push_back(arr);
            return;
        }

        for (int i = idx + 1; i <= n; i++) {
            string left = s.substr(idx, i - idx);
            if (isPalindrome[idx][i - 1]) {
                arr.push_back(left);
                rec(i, s, arr);
                arr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        int n = s.length();
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len <= 2)
                    isPalindrome[i][j] = (len == 1 || s[i] == s[j]);
                else
                    isPalindrome[i][j] =
                        (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
        rec(0, s, arr);
        return ans;
    }
};