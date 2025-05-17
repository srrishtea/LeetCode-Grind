class Solution {
public:
    int mod = 1e9 + 7;

    int power(int x, int y) {
        long long res = 1;
        long long base = x;

        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            y /= 2;
        }

        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power(2, right - left)) % mod;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
