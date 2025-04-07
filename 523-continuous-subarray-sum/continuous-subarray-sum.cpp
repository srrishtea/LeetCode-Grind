class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex;
        modIndex[0] = -1;  

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int mod = prefixSum % k;
            if (modIndex.find(mod) != modIndex.end()) {
                if (i - modIndex[mod] >= 2) {
                    return true;
                }
            } else {
                modIndex[mod] = i; 
            }
        }

        return false;
    }
};