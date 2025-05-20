class Solution {
private:
    void f(int ind, vector<int>& cur, vector<int>& nums, set<vector<int>>& st) {
        if (ind == nums.size()) {
            st.insert(cur);
            return;
        }

        cur.push_back(nums[ind]);
        f(ind + 1, cur, nums, st);
        cur.pop_back();
        f(ind + 1, cur, nums, st);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;

        vector<int> cur;

        sort(nums.begin(), nums.end());
        f(0, cur, nums, st);
        for (const auto& subset : st) {
            ans.push_back(subset);
        }

        return ans;
    }
};