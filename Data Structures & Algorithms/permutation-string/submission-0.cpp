class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.length();
        int start = 0, end = len - 1;
        sort(s1.begin(), s1.end());
        while(start + len <= s2.length())
        {
            string temp = s2.substr(start, len);
            sort(temp.begin(), temp.end());
            if(s1 == temp)
                return true;
            else
                start++;
        }
        return false;
    }
};
