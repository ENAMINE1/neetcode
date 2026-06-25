class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans;
        for (auto str : strs) {
            int len = str.length();
            str = to_string(len) + "#" + str;
            ans += str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < n;) {
            string len;
            while (s[i] != '#') {
                len += s[i];
                i++;
            }
            i++;
            int l = stoi(len);
            string word = s.substr(i, l);
            i += l;
            ans.push_back(word);
            cout << word << endl;
        }
        return ans;
    }
};
