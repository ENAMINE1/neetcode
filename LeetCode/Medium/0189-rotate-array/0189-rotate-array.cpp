class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n;

        int count = 0;

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = arr[current];

            do {
                int next = (current + k) % n;

                int temp = arr[next];
                arr[next] = prev;
                prev = temp;

                current = next;
                count++;

            } while (current != start);
        }
    }
};