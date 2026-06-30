class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0;
        int end = n - 1;
        vector<int> ans(2);
        while(start < end)
        {
            if(numbers[start] + numbers[end] > target)
                end--;
            else if(numbers[start] + numbers[end] < target)
                start++;
            else
            {
                ans = {start + 1, end + 1};
                break;
            }
        }
        return ans;
    }
};
