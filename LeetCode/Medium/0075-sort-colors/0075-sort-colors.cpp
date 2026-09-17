class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // i think i will need to use the idea for the question of move zeros 3 times here
        int boundary = 0;
        for(int val = 0; val < 3; val++){
            int j = -1;
            for(int i = 0; i < nums.size(); i++)
                if(nums[i] == val){
                    j = i;
                    break;
                }
            // if(j == -1) then there are no zeros
            if(j != -1){
                for(int i = boundary; i < n; i++)
                {
                    boundary++;
                    swap(nums[i], nums[j]);
                    // now nums[i] = 0
                    j++;
                    while(j < n && nums[j] != val)
                        j++;
                    if(j == n)
                        break;
                }
            }
        }
    }
};