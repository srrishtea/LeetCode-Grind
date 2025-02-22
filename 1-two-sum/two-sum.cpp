class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> og; 
        for (int i = 0; i < nums.size(); i++) {
            og.push_back({nums[i], i}); 
        }

        sort(og.begin(), og.end()); 

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = og[l].first + og[r].first;
            if (sum == target) {
                return {og[l].second, og[r].second}; 
            } 
            else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return {}; 
    }
};
