class Solution {

    int replacement(vector<int> &freq){
        int frequent_el = 0;
        int sum_of_all_elements = 0;
        for(int i = 0; i < 26; i++){
            frequent_el = max(frequent_el, freq[i]);
            sum_of_all_elements += freq[i];
        }
        // these many elements require replacement
        return sum_of_all_elements - frequent_el;
    }

public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int head = -1;
        int tail = 0;
        int ans = 0;
        vector<int> freq(26, 0);
        while(tail < n)
        {
            while(head + 1 < n)
            {
                head++;
                freq[s[head] - 'A']++;
                if(replacement(freq) > k){
                    freq[s[head] - 'A']--;
                    head--;
                    break;
                }
            }
            ans = max(ans, head - tail + 1);
            if(head < tail){
                tail++;
                head = tail - 1;
            }else{
                freq[s[tail] - 'A']--;
                tail++;
            }
        }
        return ans;
    }
};