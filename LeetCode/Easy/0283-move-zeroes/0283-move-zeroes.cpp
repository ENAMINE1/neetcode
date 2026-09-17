class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0){
                int j = i + 1;
                while(j < n && arr[j] == 0){
                    j++;
                }
                if(j < n){
                    arr[i] = arr[j];
                    arr[j] = 0;
                }
            }
        }
    }
};