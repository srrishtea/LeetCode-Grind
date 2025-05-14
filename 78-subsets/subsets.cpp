class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int ind, vector<int> cur) {
        if (ind == nums.size()) {
            result.push_back(cur);
            return;
        }
        solve(nums, ind + 1, cur);

        cur.push_back(nums[ind]);
        solve(nums, ind + 1, cur);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        solve(nums, 0, cur);
        return result;
    }
};
