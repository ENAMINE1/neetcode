class Solution {
    vector<vector<string>> ans;

    bool isPalindrome(string s)
    {
        int n = s.length();
        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }     

    void rec(int idx, string &s, vector<string> &arr){
        int n = s.length();
        if(idx == n){
            ans.push_back(arr);
            return;
        }

        for(int i = idx + 1; i <= n; i++)
        {
            string left = s.substr(idx, i - idx);
            if(isPalindrome(left))
            {
                arr.push_back(left);
                rec(i, s, arr);
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        rec(0, s, arr);
        return ans;
    }
};