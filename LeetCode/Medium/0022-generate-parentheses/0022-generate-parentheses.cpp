class Solution {
    vector<string> ans;

    void rec(int open, int close, string &temp, int n)
    {
        if(open + close == 2*n)
        {
            ans.push_back(temp);
            return;
        }
        if(open < n)
        {
            temp.push_back('(');
            rec(open + 1, close, temp, n);
            temp.pop_back();
        }
        if(close < open)
        {
            temp.push_back(')');
            rec(open, close + 1, temp, n);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string temp;
        rec(0, 0, temp, n);
        return ans;
    }
};