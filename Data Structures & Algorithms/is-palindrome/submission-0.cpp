class Solution {
public:
    bool isAlphanumeric(char c)
    {
        return (c <= 'z' && c >= 'A') || (c - '0' <= 9 && c - '0' >= 0);
    }

    bool isAlpha(char c)
    {
        return c <= 'z' && c >= 'A';
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r)
        {
            if(isAlphanumeric(s[l]))
            {
                if(isAlphanumeric(s[r]))
                {
                    if(isAlpha(s[l]) && isAlpha(s[r]))
                    {
                        s[l] = std::tolower(s[l]);
                        s[r] = std::tolower(s[r]);
                    }
                    if(s[l] != s[r])
                        return false;
                    else
                    {
                        l++;
                        r--;
                    }
                }
                else
                    r--;
            }
            else
                l++;
        }
        return true;
    }
};
