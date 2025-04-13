class Solution {
public:
    int findLastIndex(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int ind = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if (ind == nums.size() || nums[ind] != target)
            return {-1, -1};

        int lastInd = findLastIndex(nums, target);
        return {ind, lastInd};
    }
};
