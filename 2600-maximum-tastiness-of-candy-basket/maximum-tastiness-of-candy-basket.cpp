class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0, right = price.back() - price.front(), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 1, last = price[0];

            for (int i = 1; i < price.size(); ++i) {
                if (price[i] - last >= mid) {
                    count++;
                    last = price[i];
                }
            }

            if (count >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};