class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int currentStreak = nums[0];
        int previousStreak = 0;
        int longest = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                currentStreak++;
            } else {
                longest = max(longest, currentStreak + previousStreak);
                previousStreak = (nums[i - 1] == 1 ? currentStreak : 0);
                currentStreak = 0;
            }
        }

        longest = max(longest, currentStreak + previousStreak);
        return (longest >= n) ? n - 1 : longest;
    }
};