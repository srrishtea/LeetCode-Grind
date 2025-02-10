class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,i=0;
        while(i<nums.size()) {
            if(nums[i]==1) {
                int sz=0;
                while(i < nums.size() && nums[i] == 1) {
                    sz++;
                    i++;
                }
                ans=max(ans,sz);
            }
            i++;
        }
        return ans;
    }
};